procedure bit(n:int)
    var ans := 0
    loop
        n := n / 10
        ans := ans + 1
        exit when (n <= 0)
    end loop
    put ans
    skip
    return
end bit

bit(0)
bit(1234)
bit(15345)