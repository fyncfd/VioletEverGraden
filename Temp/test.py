# @Author: AlgoStruggler
# @Date:   2026-04-12 14:56:55
# @Create Time: 2026-04-12 14:56:55
# "To the Splendor of ACM-ICPC, We Consecrate Our AC Triumphs."
#
USE_FAST_IO = 1
USE_ALL_PACKAGES = 1
USE_ADVANCED_FEATURES = 1
OUTPUT_TOGETHER = 0
DFS = 0
HASHING = 0
#

if True:
	if USE_ALL_PACKAGES:
		from collections import *
		from itertools import *
		from functools import *
		from bisect import *
		from heapq import *
		import sys

		if USE_ADVANCED_FEATURES:
			from io import BytesIO, IOBase
			import random
			import os
			from copy import deepcopy
			from operator import *
			from string import *
			from typing import *
			BUFSIZE = 4096

	if USE_FAST_IO:
		import io, os, sys
		input = lambda: sys.stdin.readline().strip()

		import math
		inf = math.inf

		def I():
			return input()

		def II():
			return int(input())

		def MII():
			return map(int, input().split())

		def LI():
			return input().split()

		def LII():
			return list(map(int, input().split()))

		def LFI():
			return list(map(float, input().split()))

		def GMI():
			return map(lambda x: int(x) - 1, input().split())

		def LGMI():
			return list(map(lambda x: int(x) - 1, input().split()))

	if OUTPUT_TOGETHER:
		class FastIO(IOBase):
			newlines = 0

			def __init__(self, file):
				self._fd = file.fileno()
				self.buffer = BytesIO()
				self.writable = "x" in file.mode or "r" not in file.mode
				self.write = self.buffer.write if self.writable else None

			def read(self):
				while True:
					b = os.read(self._fd, max(os.fstat(self._fd).st_size, BUFSIZE))
					if not b:
						break
					ptr = self.buffer.tell()
					self.buffer.seek(0, 2), self.buffer.write(b), self.buffer.seek(ptr)
				self.newlines = 0
				return self.buffer.read()

			def readline(self):
				while self.newlines == 0:
					b = os.read(self._fd, max(os.fstat(self._fd).st_size, BUFSIZE))
					self.newlines = b.count(b"\n") + (not b)
					ptr = self.buffer.tell()
					self.buffer.seek(0, 2), self.buffer.write(b), self.buffer.seek(ptr)
				self.newlines -= 1
				return self.buffer.readline()

			def flush(self):
				if self.writable:
					os.write(self._fd, self.buffer.getvalue())
					self.buffer.truncate(0), self.buffer.seek(0)

		class IOWrapper(IOBase):
			def __init__(self, file):
				self.buffer = FastIO(file)
				self.flush = self.buffer.flush
				self.writable = self.buffer.writable
				self.write = lambda s: self.buffer.write(s.encode("ascii"))
				self.read = lambda: self.buffer.read().decode("ascii")
				self.readline = lambda: self.buffer.readline().decode("ascii")

		sys.stdout = IOWrapper(sys.stdout)

	if DFS:
		from types import GeneratorType

		def bootstrap(f, stk=[]):
			def wrappedfunc(*args, **kwargs):
				if stk:
					return f(*args, **kwargs)
				else:
					to = f(*args, **kwargs)
					while True:
						if type(to) is GeneratorType:
							stk.append(to)
							to = next(to)
						else:
							stk.pop()
							if not stk:
								break
							to = stk[-1].send(to)
					return to
			return wrappedfunc

	if HASHING:
		RANDOM = random.getrandbits(20)
		class Wrapper(int):
			def __init__(self, x):
				int.__init__(x)

			def __hash__(self):
				return super(Wrapper, self).__hash__() ^ RANDOM

	fmax = lambda x, y: x if x > y else y
	fmin = lambda x, y: x if x < y else y
	fabs = lambda x: x if x >= 0 else -x

def VioletEverGraden():
	n = II()
	a = LII()
	print(*a, sep = ' ')

if __name__ == "__main__":
	T = 1
	T = II()
	
	for _ in range(T):
		VioletEverGraden()