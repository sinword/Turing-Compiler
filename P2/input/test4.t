function add (a :int, b :int) :int
    result 123
end add
    
procedure sub (a :int, b :int)
    return
end sub

% invalid fun grammar use result in procedure
procedure pro1 ()
    result 1
end pro1

% invalid pro grammar use return in function
function fun1 (): int
    return    
end fun1

% invalid parameter type 
var a := sub(1, "123")

% wrong parameter number
const b := add(1, 2 ,3)

% not declared function 
var c :int :=min()

const d :bool :=add(1, 2)