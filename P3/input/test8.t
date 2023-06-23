% boolean expression
put not true %0
skip
put not false %1
skip
put not not true %1
skip
put true and true %1
skip
put true and false %0
skip
put false or true %1
skip
put false or false %0
skip
put false or not true %0
skip
put true and not false %1
skip
put 1 < 2 %1
skip
put 1 > 3 %0
skip
put 1 = 1 %1
skip
put 1 not= 2 %1
skip
put 1 >= 1 %1
skip
put 1 < 2 and 2 < 3 %1
skip
put 1 > 2 or 1 >= 0 %1
skip