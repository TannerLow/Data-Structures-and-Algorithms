math.randomseed(os.time());math.random()
--Question 1
input = io.read()
n = #input
left,right = 1,n
while left <= right do
	mid = left + math.floor((right-left)/2)
	if input:sub(mid,mid+1) == "01" then
		print(mid)
		break
	elseif input:sub(mid-1,mid) == "01" then
		print(mid-1)
		break
	elseif input:sub(mid,mid) == "0" then left = mid+1
	else right = mid-1 end
end

--Question 2
--Creating 2 arrays of random sorted ints
n = 16
a = {}
b = {}

for i=1,n do
	a[i] = math.random(0,1000)
	b[i] = math.random(0,1000)
end

table.sort(a)
table.sort(b)

--function to get median
function median(arr,left,right)
	local mid = (right-left)/2
	local a, b = math.floor(mid), math.ceil(mid)
	return (arr[left+a] + arr[left+b])/2
end

--functions to get midpoint
function midpointL(left,right)
	return math.floor((right-left)/2) + left
end
function midpointU(left,right)
	return math.ceil((right-left)/2) + left
end

--function to solve Question 2 O(logn)
function combinedMedian(a,b)
	local  leftA, leftB  = 1, 1
	local rightA, rightB = table.getn(a), table.getn(b)
	while rightA-leftA > 1 do
		if median(a,leftA,rightA) < median(b,leftB,rightB) then
			leftA  = midpointL(leftA, rightA)
			rightB = midpointU(leftB, rightB)
		elseif median(a,leftA,rightA) > median(b,leftB,rightB) then
			rightA = midpointU(leftA, rightA)
			leftB  = midpointL(leftB, rightB)
		else
			return median(a,leftA,rightA)
		end
	end
	return (math.max(a[leftA],b[leftB]) + math.min(a[rightA],b[rightB]))/2
end

print("Algorithm: "..combinedMedian(a,b))

--Determines correct answer for comparison O(nlogn)
c = {}
for i=1,16 do
	c[i] = a[i]
end
for i=17,32 do
	c[i] = b[i-16]
end
table.sort(c)
print("Actual   : "..(c[16] + c[17])/2)

