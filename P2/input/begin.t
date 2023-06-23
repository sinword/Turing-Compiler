const n: int := 10
var sum: int
var index: int
var f : real


begin
  var b1: string
  var b: array 0..5 of bool
  sum := 0
  index := 1
  put sum
  skip
end


% loop
sum := 0
index := 1
loop
  sum := sum + index
  index := index + 1
  exit when index = n
end loop
put "The result is "
put sum
