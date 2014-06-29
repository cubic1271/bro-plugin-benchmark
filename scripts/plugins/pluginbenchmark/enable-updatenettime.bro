event bro_init() {
	PluginBenchmark::EnableHook(4);
}

event bro_done() {
	print(fmt("Number of net time advances: %d", PluginBenchmark::GetHookCount()));
}
