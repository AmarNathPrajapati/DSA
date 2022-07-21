''' dynamic programming implementation of 0-1 Knapsack Problem Returns the maximum value that
can be put in a knapsack ofcapacity W '''

def knapSack(W, wt, val, n):
	if n == 0 or W == 0:
		return 0

	# '''If weight of the nth item is more than Knapsack of capacity W then this item cannot be included
	# in the optimal solution''' 
	if (wt[n-1] > W):
		return knapSack(W, wt, val, n-1)

	# return the maximum of two cases:
	# (1) nth item included
	# (2) not included
	else:
		return max(val[n-1] + knapSack(W-wt[n-1], wt, val, n-1),knapSack(W, wt, val, n-1))
    # end of function knapSack
    
#Driver Code
value = [80,200,90,70]
weight = [30,70,40,20]
capacity = 60
n = len(value)
ans = knapSack(capacity, weight, value, n)
print(ans)
