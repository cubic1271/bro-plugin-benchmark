event bro_init() {
	PluginBenchmark::EnableHook(1);
}

event bro_done() {
	print(fmt("Number of script calls: %d", PluginBenchmark::GetHookCount()));
}
