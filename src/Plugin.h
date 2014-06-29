#ifndef _BRO_PLUGIN_BENCHMARK_H
#define _BRO_PLUGIN_BENCHMARK_H

#include <Func.h>
#include <plugin/Plugin.h>
#include <plugin/Manager.h>

namespace plugin {
	namespace Plugins_PluginBenchmark {
		class Plugin : public plugin::Plugin
		{
		protected:
			plugin::Configuration Configure()
				{
				plugin::Configuration config;
				config.name = "Plugins::PluginBenchmark";
				config.description = "Selectively enables / disables certain hooks to test performance impact";
				config.version.major = 1;
				config.version.minor = 0;
				return config;
				}
				
			int counter;
		public:
			Plugin()
			: counter(0) { }
			
			/**
			Thin wrapper to fix visibility and convert type.
			
			@param hook Hook ID
			*/
			void DoEnableHook(int hook) {
				this->EnableHook((HookType)hook);
			}

			/**
			Thin wrapper to fix visibility and convert type.
			
			@param hook Hook ID
			*/
			void DoDisableHook(int hook) {
				this->DisableHook((HookType)hook);
			}

			/**
			Returns a count of how many times hooks have called functions in this class.

			@return A count of how many times hooks have called functions in this class.
			*/
			int GetCounter() {
				return counter;
			}

			virtual int HookLoadFile(const std::string& file, const std::string& ext)
			{
				++counter;
				return -1;
			}

			virtual Val* HookCallFunction(const Func* func, val_list* args)
			{
				++counter;
				return NULL;
			}

			virtual bool HookQueueEvent(Event* event)
			{
				++counter;
				return false;
			}

			virtual void HookDrainEvents()
			{
				++counter;
				return;
			}

			virtual void HookUpdateNetworkTime(double network_time)
			{
				++counter;
				return;
			}

			virtual void HookBroObjDtor(void* obj)
			{
				++counter;
				return;
			}

		};

		extern Plugin plugin;
	}
}

#endif //_BRO_PLUGIN_BENCHMARK_H
