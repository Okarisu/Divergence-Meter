# Divergence meter

## from Steins;Gate series and visual novels

## Note - this `readme` is in process of writing, the same as the code

## Basic synopsis

In this project I am trying to build working prototype of Divergence meter that appeared in Steins;Gate anime series and Visual novels.

![Divergence meter](https://raw.githubusercontent.com/Okarisu/Divergence-Meter/main/images/Divergence_Meter.webp)

I use arduino board in combination with shift registers SN74HC595N to drive itrons IV-6.

## byte values for shift registers

### Grids

| Itron No. | byte value |
| --------- | ---------- |
| first |  B01111111 |
| second | B10111111 |
| third | B11011111 |
| fourth | B11101111 |
| fifth | B11110111 |
| sixth | B11111011 |
| seventh | B11111101 |
| eighth | B11111110 |

### Numbers & symbols

| Number | byte value |
| ------ | ---------- |
| zero | B00000011 |
| one | B10011111 |
| two | B00100101 |
| three | B00001101 |
| four | B10110001 |
| five | B01001001 |
| six | B01000001 |
| seven | B00011111 |
| eight | B00000001 |
| nine | B00001001 |

| symbol | byte value |
| ------ | ---------- |
| dot | B11111110 |
| stroke | B11111101 |
