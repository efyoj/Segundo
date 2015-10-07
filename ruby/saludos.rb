#!/usr/bin/env ruby
# saludos.rb
# Demonstrates de use of blocks


def saluda(name)
	name.each { |e| yield e}
end

primo = []
perfectos = []

saluda(%w[manolo juan pepe nicasio alberto]) do |nombre| 
	puts "hola, #{nombre}."
end