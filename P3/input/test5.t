var grade := 59

if grade >= 90 then
    put "A"
else
    if grade >= 70 and grade < 90 then
        put "B"
    else
        if grade >= 60 and grade <= 70 then
            put "C"
        end if
        if grade < 60 then
            put "D"
        end if
    end if
end if