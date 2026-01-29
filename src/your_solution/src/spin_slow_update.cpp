#include "spin_slow_update.h"
#include <functional>
#include <sstream>



int main(int argc, char *argv[]) {
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<SlowSolution>());
  rclcpp::shutdown();
  return 0;
}

SlowSolution::SlowSolution() : Node("slowsolution") {
  RCLCPP_INFO(this->get_logger(), "Remove this statement from spin_slow_update.cpp");
  // your code here
  // auto qos = rclcpp::QoS(rclcpp::KeepLast(10)).best_effort();
  subscriber_ = this->create_subscription<std_msgs::msg::Float64MultiArray>(
      "/measuredpos", 10,
      std::bind(&SlowSolution::topic_callback, this, std::placeholders::_1));
  pub_ = this->create_publisher<std_msgs::msg::Float64MultiArray>(
            "/predictedpos", 10);
}
  

void SlowSolution::topic_callback(const std_msgs::msg::Float64MultiArray::SharedPtr msg) {
  RCLCPP_INFO(this->get_logger(), "Test");
  std::stringstream ss;
  this->x = msg->data[0];
  this->y = msg->data[1];
  std_msgs::msg::Float64MultiArray out_msg;
  out_msg.data = msg->data;
  pub_->publish(out_msg);
  for (auto v : msg->data) {
    ss << v << " ";
  }

  RCLCPP_INFO(this->get_logger(), "I heard: '%s'", ss.str().c_str());

}

