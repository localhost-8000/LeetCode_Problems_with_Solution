// Brute force method...
```
1. max_area = INT_MIN

2. for every arr[i]:
  1. curr_height = arr[i]
  2. find left_smaller_index i.e. first leftmost index with height < curr_height
  3. find right_smaller_index i.e. first rightmost index with height < curr_height
  4. width = (right_smaller_index - left_smaller_index + 1)
  5. curr_area = curr_height * width
  6. max_area = max(curr_area, max_area)
end for loop

3. return max_area
```

Overall time complexity -> O(N*N)
<hr />

// Optimized method...
```
1. create a stack st that will store indexes
2. create two array left_smaller and right_smaller that will store leftmost smaller and rightmost smaller index for a index i respectively.

// calculate left smaller...
3. for every arr[i]:
  i. curr_height = arr[i]
  // stack_top_height means arr[st.top()]
  ii. while stack is not empty and stack_top_height >= curr_height:
          -> stack.pop()
  iii. if stack is empty left_smaller[i] = 0
      else left_smaller[i] = st.top() + 1
  iv. st.push(i);
end for loop
  
4. clear stack for reuse

// calculate right smaller...this time traverse from back..
5. for every arr[i] 
  i. curr_height = arr[i]
  ii. while stack is not empty and stack_top_height >= curr_height:
      stack.pop()
  iii. if stack is empty right_smaller[i] = n-1
       else right_smaller[i] = st.top() - 1
  iv. st.push(i)
end for loop
 
6. max_area = INT_MIN
7. for every arr[i]
  i. curr_height = arr[i]
  ii. width = (right_smaller[i] - left_smaller[i] + 1)
  iii. max_area = max(max_area, curr_height * width)
end for loop

8. return max_area
```
Time complexity = O(N)
Space complexity = O(N)
