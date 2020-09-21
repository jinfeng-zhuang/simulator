# riscv-simulator

## OVERVIEW

The simualtor targets on RV64I.

## ENV

1. download gnu toolchain from sifive: https://www.sifive.com/products/tools/
2. create start.S, layout.lds and Makefile

## REFERENCE

* https://github.com/jinfeng-zhuang/riscv-opcodes

	cat opcodes-pseudo opcodes opcodes-rvc opcodes-rvc-pseudo opcodes-custom | ./parse-opcodes -c > temp.h

* https://nitish2112.github.io/post/adding-instruction-riscv/
