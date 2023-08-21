
SHELL=/bin/bash


demo-listener:
	ros2 run demo_nodes_cpp listener

demo-talker:
	ros2 run demo_nodes_cpp talker

build-interfaces:
	colcon build --packages-select tutorial_interfaces

build-pubsub:
	colcon build --packages-select cpp_pubsub

run-pubsub-listener:
	source install/setup.sh ; ros2 run cpp_pubsub listener

run-pubsub-talker:
	source install/setup.sh ; ros2 run cpp_pubsub talker

build-addint:
	colcon build --packages-select cpp_addint

run-addint-server:
	source install/setup.sh ; ros2 run cpp_addint server

run-addint-client:
	source install/setup.sh ; ros2 run cpp_addint client

