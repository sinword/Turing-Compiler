% Variable declaration tests

var s1: string := "hello"
var s2: string
var s3 := "world"
var s4: array 1..10 of string

var i1: int := 1
var i2: int
var i3 := 2
var i4 := i1 + i3
var i5: array 1..10 of int
var i6 : array 10..1 of int

var f1: real := 1.0
var f2: real
var f3 := 2.0
var f4 := f1 + f3 + i1 + i3
var f5: array 1..10 of real

var b1: bool := true
var b2: bool
var b3 := false
var b4 := 1
var b5 := 0
var b6: array 1..10 of bool

% Comment are erroneous syntax

i5[5] := f5[1] + b6[2]
s4[4] := i5[5]