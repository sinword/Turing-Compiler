% Binary Search Algorithm

% Function to perform binary search
function BinarySearch (arr: array 1..10 of int, low: int, high: int, target: int): int
    var mid: int
    for low: 1..high
        mid := (low + high) / 2
        if arr[mid] = target then
            result mid
        else
            if arr[mid] < target then
                low := mid + 1
            else
                high := mid - 1
            end if
        end if
    end for
    result -1
end BinarySearch

% Main program
procedure main()
    var arr: array 1..10 of int % sorted array 
    var target :int := 6  % element to be searched
    var low :int := 1
    var high :int := 10
    var index :int

    index := BinarySearch(arr, low, high, target)

    if index >= 0 then
        put index
    else 
        put "Element not found"
    end if
    return
end main

% Run the main program
var tmp := main()