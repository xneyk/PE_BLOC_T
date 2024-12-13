import sys
import time

def usage():
   print("usage: python linear_search.py <set_length>", file=sys.stderr)
   print("reads from stdin <set_length> rows formatted as: x n array[n]", file=sys.stderr)
   print("where 'x' is a value in the array and 'array' is an array with length 'n'", file=sys.stderr)
   sys.exit(1)

def read_vector(line):
   parts = list(map(int, line.split()))
   x = parts[0]   # First value is the number to find
   n = parts[1]   # Second value is the length of the vector.
   if len(parts) != n + 1:
      print(f"Error: Expected {n + 1} values, got {len(parts)}", file=sys.stderr)
      sys.exit(1)
   v = parts[2:]  # Remaining values are the vector
   return x, n, v

def linear_search(x, v):
   for i, val in enumerate(v):
      if val == x:
         return i
   return -1  # never reached because precondition: x exists in v.

def main():
   if len(sys.argv) != 2:
      usage()

   try:
      set_length = int(sys.argv[1])
   except ValueError:
      usage()

   for _ in range(set_length):
      line = input().strip()  # Read the entire line
      x, n, v = read_vector(line)
      
      start = time.perf_counter_ns()  # mark start time
      linear_search(x, v)
      end = time.perf_counter_ns()  # mark end time

      # calc delta and print elapsed time
      duration = end - start
      print(f"{duration}") # time in nanoseconds

if __name__ == "__main__":
   main()
