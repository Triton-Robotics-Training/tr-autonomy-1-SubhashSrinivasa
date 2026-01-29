#ifndef YOUR_SOLUTION_SRC_SPIN_SLOW_UPDATE_H_
#define YOUR_SOLUTION_SRC_SPIN_SLOW_UPDATE_H_

#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/float64_multi_array.hpp"
#include "std_msgs/msg/string.hpp"
using ArrayMsg = std_msgs::msg::Float64MultiArray;

class SlowSolution : public rclcpp::Node {
 public:
  SlowSolution();
 private:
  double x;
  double y;
  void topic_callback(const std_msgs::msg::Float64MultiArray::SharedPtr msg);
  
  rclcpp::Subscription<std_msgs::msg::Float64MultiArray>::SharedPtr subscriber_;
  rclcpp::Publisher<std_msgs::msg::Float64MultiArray>::SharedPtr pub_;
};

#endif //YOUR_SOLUTION_SRC_SPIN_SLOW_UPDATE_H_
