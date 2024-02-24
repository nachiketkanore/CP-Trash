# code converted using chatGPT
#!/usr/bin/env tclsh

# Author: Nachiket Kanore
# Created: Saturday 24 February 2024 11:30:51 AM IST

set _ 200000

array set prime {}
set prime(0) false
set prime(1) false
set prime(2) true

for {set i 3} {$i <= $_} {incr i} {
    set prime($i) true
}

for {set i 2} {$i * $i <= $_} {incr i} {
    if {$prime($i)} {
        for {set j [expr {$i * $i}]} {$j <= $_} {incr j $i} {
            set prime($j) false
        }
    }
}

set primes {}
for {set i 2} {$i <= $_} {incr i} {
    if {$prime($i)} {
        lappend primes $i
    }
}

gets stdin N

set largest_less_than_N -1
for {set i 0} {$i < [llength $primes]} {incr i} {
    if {[lindex $primes $i] <= $N} {
        set largest_less_than_N [lindex $primes $i]
    } else {
        break
    }
}

set smallest_greater_than_N $_
for {set i 0} {$i < [llength $primes]} {incr i} {
    if {[lindex $primes $i] >= $N} {
        set smallest_greater_than_N [lindex $primes $i]
        break
    }
}

puts "$largest_less_than_N $smallest_greater_than_N"
