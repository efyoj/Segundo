#!/usr/bin/env ruby
# primos_fijos.rb
# Demonstrates de use of blocks

require 'prime'

primo = []
perfectos = []

(1..100).each{ |x| primo << x if Prime.prime? x }
(1..100).each do |x| 
	divisores = []
	(x/2).downto(1) { |n| divisores << n if x % n == 0}

	perfectos << x if divisores.inject(0) { |mem, var| mem + var } == x
end

p primo
p perfectos