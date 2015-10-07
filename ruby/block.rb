#!/usr/bin/env ruby
# block.rb
# Demonstrates de use of blocks

primo = []
perfectos = []

def a(name)
	yield name [0]
end

a(["manolo", "juan"]) do |nombre| 
	puts "hola, #{nombre}."
end