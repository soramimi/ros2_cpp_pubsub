#include "rclcpp/rclcpp.hpp"
#include "tutorial_interfaces/srv/add_int.hpp"
#include <chrono>
#include <cstdlib>
#include <memory>

using namespace std::chrono_literals;

int main(int argc, char **argv)
{
	rclcpp::init(argc, argv);

	std::shared_ptr<rclcpp::Node> node = rclcpp::Node::make_shared("add_int_client");
	rclcpp::Client<tutorial_interfaces::srv::AddInt>::SharedPtr client = node->create_client<tutorial_interfaces::srv::AddInt>("add_int");

	auto request = std::make_shared<tutorial_interfaces::srv::AddInt::Request>();

	request->left = 123;
	request->right = 654;

	while (!client->wait_for_service(1s)) {
		if (!rclcpp::ok()) {
			RCLCPP_ERROR(rclcpp::get_logger("rclcpp"), "Interrupted while waiting for the service. Exiting.");
			return 0;
		}
		RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "service not available, waiting again...");
	}
	auto result = client->async_send_request(request);
	// Wait for the result.
	if (rclcpp::spin_until_future_complete(node, result) == rclcpp::FutureReturnCode::SUCCESS) {
		RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "Sum: %d", result.get()->result);
	} else {
		RCLCPP_ERROR(rclcpp::get_logger("rclcpp"), "Failed to call service add_int");
	}
	rclcpp::shutdown();
	return 0;
}
