
cmake_minimum_required(VERSION 2.6.3)

project(Plugin)

include(BroPlugin)

bro_plugin_begin(Plugins PluginBenchmark)
bro_plugin_cc(src/Plugin.cc)
bro_plugin_bif(src/consts.bif)
bro_plugin_bif(src/events.bif)
bro_plugin_bif(src/functions.bif)
bro_plugin_end()
