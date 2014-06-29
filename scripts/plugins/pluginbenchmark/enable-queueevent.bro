event bro_init() {
	PluginBenchmark::EnableHook(2);
}

event bro_done() {
	print(fmt("Number of queued events: %d", PluginBenchmark::GetHookCount()));
}
