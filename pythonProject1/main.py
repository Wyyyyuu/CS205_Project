import json
import matplotlib.pyplot as plt

def plot_results(filename, label):
    # Load the benchmark results from the JSON file
    with open(filename) as f:
        data = json.load(f)

    # Extract the benchmark names, data sizes, and timings
    benchmarks = data['benchmarks']
    sizes = [int(bench['name'].split('/')[1]) for bench in benchmarks]
    times = [bench['real_time'] for bench in benchmarks]

    # Plot the results
    plt.plot(sizes, times, 'o-', label=label)

# Plot the results from result.json
plot_results('openmp.json', 'openmp')
plot_results('block.json', 'block')





# Plot the results from result2.json
plot_results('cblas.json', 'cblas')

# Customize the plot
plt.xlabel('Data Size')
plt.ylabel('Time (ms)')
plt.title('Benchmark Results')
plt.legend()
plt.grid(True)
plt.show()