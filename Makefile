
SHELL=/bin/bash


demo-listener:
	ros2 run demo_nodes_cpp listener

demo-talker:
	ros2 run demo_nodes_cpp talker

build-interfaces:
	colcon build --packages-select tutorial_interfaces

build-pubsub:
	colcon build --packages-select cpp_pubsub

run-listener:
	source install/setup.sh ; ros2 run cpp_pubsub listener

run-talker:
	source install/setup.sh ; ros2 run cpp_pubsub talker
