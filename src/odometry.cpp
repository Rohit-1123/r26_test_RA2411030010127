#include "odometry.h"
#include <cmath>
#include <vector>
#include <utility>

using namespace std;

Odometry::Odometry(double wheel_radius, double rpm)
    : radius(wheel_radius), rpm(rpm) {
  // Linear velocity (m/s) = (wheel circumference * revolutions per second)
  double rps = rpm / 60.0;
  linear_vel = 2 * M_PI * radius * rps;
}

double Odometry::distance(int x1, int y1, int x2, int y2) {
  return sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
}

double Odometry::angle(int x1, int y1, int x2, int y2) {
  // atan2 returns radians, convert to degrees
  return atan2(y2 - y1, x2 - x1) * 180.0 / M_PI;
}

MotionCommand Odometry::computeCommands(vector<pair<int, int>> &path) {
  MotionCommand res = {0.0, 0.0}; // total_time, total_angle

  if (path.size() < 2 || linear_vel <= 0.0) {
    return res; // no movement or invalid velocity
  }

  double total_distance = 0.0;
  double total_angle = 0.0;

  // Start heading
  double prev_angle = angle(path[0].first, path[0].second,
                            path[1].first, path[1].second);

  for (size_t i = 1; i < path.size(); i++) {
    // Distance between consecutive points
    total_distance += distance(path[i-1].first, path[i-1].second,
                               path[i].first, path[i].second);

    // Compute turn angle 
    if (i + 1 < path.size()) {
      double next_angle = angle(path[i].first, path[i].second,
                                path[i+1].first, path[i+1].second);
      double diff = next_angle - prev_angle;


      while (diff > 180) diff -= 360;
      while (diff < -180) diff += 360;

      total_angle += fabs(diff);
      prev_angle = next_angle;
    }
  }

  // Time = distance / velocity
  res.total_time = total_distance / linear_vel;
  res.total_angle = total_angle;

  return res;
}
