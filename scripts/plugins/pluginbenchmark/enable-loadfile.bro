event bro_init() {
	PluginBenchmark::EnableHook(0);
}

event bro_done() {
	print(fmt("Number of files loaded: %d", PluginBenchmark::GetHookCount()));
}
