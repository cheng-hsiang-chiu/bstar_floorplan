import matplotlib
import matplotlib.pyplot as plt
import numpy as np
import sys
import matplotlib as mpl

mpl.rcParams['agg.path.chunksize'] = 10000


inputfile = sys.argv[1]

cost = []
with open(inputfile) as f:
  costs = f.readlines()
  for c in costs:
    cost.append(c)



x = np.arange(0, len(cost), 1)
y = cost

fig, ax = plt.subplots()
ax.plot(x[:100000], y[:100000])
#ax.semilogy(x, y)

plt.savefig("test.png", dpi=2000)
#plt.show()

