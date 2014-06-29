event bro_init() {
	PluginBenchmark::EnableHook(5);
}

event bro_done() {
	print(fmt("Number of object dtor: %d", PluginBenchmark::GetHookCount()));
}
