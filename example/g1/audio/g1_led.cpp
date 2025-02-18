#include <fstream>
#include <iostream>
#include <unitree/common/time/time_tool.hpp>
#include <unitree/idl/ros2/String_.hpp>
#include <unitree/robot/channel/channel_subscriber.hpp>
#include <unitree/robot/g1/audio/g1_audio_client.hpp>


int main(int argc, char const *argv[]) {
  if (argc < 2) {
    std::cout << "Usage: audio_client_example [NetWorkInterface(eth0)]"
              << std::endl;
    exit(0);
  }
  /*
   * Initilaize ChannelFactory
   */
  unitree::robot::ChannelFactory::Instance()->Init(0, argv[1]);
  unitree::robot::g1::AudioClient client;
  client.Init();
  client.SetTimeout(10.0f);


  /*LED Control Example*/
  client.LedControl(0, 0, 0);
  unitree::common::Sleep(1);

  std::cout << "RED" << std::endl;
  client.LedControl(255, 0, 0);
  unitree::common::Sleep(2);
  std::cout << "GREEN" << std::endl;
  client.LedControl(0, 255, 0);
  unitree::common::Sleep(2);
  std::cout << "BLUE" << std::endl;
  client.LedControl(0, 0, 255);
  unitree::common::Sleep(2);


  return 0;
}