var counter :int
var i := 1

function isPrime (n: int) : int
    var counter := 0
    loop
        exit when i > n
        if n mod i = 0 then
            put n
            put " can be mod = 0 by "
            put i
            skip
            counter := counter + 1
        end if
        i := i + 1
    end loop
    put "counter: " 
    put counter
    skip
    if counter = 2 then
        result 1
    else
        result 0
    end if
    
end isPrime

if isPrime(13) then
    put "Yes"
else
    put "No"
end if
skip