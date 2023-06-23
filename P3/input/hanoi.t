{% recursive %}

procedure hanoi(n: int, s: int, d: int, a: int)
    if n = 1 then
        put n
        put ": "
        put s
        put " > "
        put d
        skip
    else
        hanoi(n - 1, s, a, d) % 將較小的 n-1 塔從原位置移動到輔助位置
        put n
        put ": "
        put s
        put " > "
        put d
        skip
        hanoi(n - 1, a, d, s)  % 將之前移動到輔助位置的 n-1 塔移動到目標位置
    end if
    return
end hanoi

hanoi(3,1,2,3)