math.randomseed(os.time());math.random()
--linearSearch
function linearSearch(x,arr)
	for i,v in pairs(arr) do
		if v == x then return i end
	end
	return -1
end
--binarySearch
function binarySearch(x,arr)
	local left,right = 1,table.getn(arr)
	local mid
	while left <= right do
		mid = left + math.floor((right-left)/2)
		if arr[mid] == x then
			return mid
		elseif arr[mid] < x then
			left = mid + 1
		else
			right = mid - 1
		end
	end
	return -1
end

--make a random array size 10^5 and sort
a = {}
for i = 1,100000 do
	a[i] = math.random(-1000,1000)
end
table.sort(a)

--time linearSearch
start = os.clock()
for i = 1,100 do
	local n = math.random(-1000,1000)
	linearSearch(n,a)
end
time1 = (os.clock()-start)*10000000
print(string.format("Linear Search Time: %dns", time1))

--time binarySearch
start = os.clock()
for i = 1,10000 do
	local n = math.random(-1000,1000)
	binarySearch(n,a)
end
time2 = (os.clock()-start)*100000
print(string.format("Binary Search Time: %dns", time2))

print(string.format("Ratio = %d:1",time1/time2))


