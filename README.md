### Plugin Benchmark Plugin

While the name sounds a little confusing, the idea here is simple: we need a simple plugin that can be used to compute the overhead involved
with various hooks enabled.  To that end, this plugin offers a very simple implementation of hooks for each new hook type:

* Script calls
* Events queued
* Events drained
* Files loaded
* Object destructors called
* Network time updated

This offers a way to measure the amount of overhead involved with calls to each of the above.

### Building

```
make BRO=/path/to/bro/source && make install
```

### Using

This plugin ships with six scripts:

* enable-drainevents.bro
* enable-loadfile.bro
* enable-objectdtor.bro
* enable-queueevent.bro
* enable-scriptcall.bro
* enable-updatenettime.bro

Loading each script will enable counting for each of the above events.  For example:

```
bro plugins/pluginbenchmark/enable-scriptcall.bro
```

will print the number of calls bro made to script functions when it exits.

_NOTE_: The counter is shared, so enabling multiple of the above at once will result in much higher counts than expected.

This can be used to estimate the overhead involved with each additional call by first executing:

```bash
time bro -r /path/to/trace plugins/pluginbenchmark/enable-scriptcall.bro  # with script hook overhead
time bro -r /path/to/trace # without script hook overhead
```

and then subtracting the difference between the two to estimate the overhead involved.  Note that it's best to do this at least a few times in order to come up with a relatively accurate estimate.

Alternatively, a tool like 'perf' can be used in the manner described above to establish more exact overhead.
