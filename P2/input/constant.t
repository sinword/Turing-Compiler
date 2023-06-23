% Constant declaration tests

const s1: string := "hello"
% const s2: string
const s3 := "world"
% const s4: array 1..10 of string

const i1: int := 1
% const i2: int
const i3 := 2
const i4 := i1 + i3
% const i4: array 1..10 of int

const f1: real := 1.0
% const f2: real
const f3 := 2.0
const f4 := f1 + f3 + i1 + i3
% const f4: array 1..10 of real

const b1: bool := true
% const b2: bool
const b3 := false
const b4 := 1
const b5 := 0
% const b6: array 1..10 of bool

% Comment are erroneous syntax