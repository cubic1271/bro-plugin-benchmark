event bro_init() {
	PluginBenchmark::EnableHook(3);
}

event bro_done() {
	print(fmt("Number of times events were drained: %d", PluginBenchmark::GetHookCount()));
}
