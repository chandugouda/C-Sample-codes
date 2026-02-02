# 🧠 Microcontroller (MCU) -- Quick Interview Cheat Sheet

### (General + 8051 Specific)

This document is intended for **embedded / automotive interview
preparation**. Covers **basic but high-priority MCU fundamentals**,
including **architecture questions** that interviewers frequently ask.

------------------------------------------------------------------------

## 1. What is a Microcontroller?

A **microcontroller (MCU)** is a single-chip system that integrates: -
CPU - Memory - Peripherals

Used for **real-time control** of hardware.

------------------------------------------------------------------------

## 2. Harvard vs Von Neumann Architecture (VERY COMMON 🔥)

### Von Neumann Architecture

-   Single memory for **code and data**
-   Single bus for instruction & data

```{=html}
<!-- -->
```
    CPU ↔ Memory (Code + Data)

#### Pros:

-   Simple design

#### Cons:

-   Slower (instruction fetch & data access share bus)

------------------------------------------------------------------------

### Harvard Architecture

-   **Separate memory** for code and data
-   **Separate buses**

```{=html}
<!-- -->
```
    CPU ↔ Program Memory
    CPU ↔ Data Memory

#### Pros:

-   Faster execution
-   Parallel instruction & data access

#### Cons:

-   Slightly complex hardware

------------------------------------------------------------------------

### Modified Harvard (Most MCUs)

-   Separate code & data memory
-   Data can be accessed from program memory if needed

📌 **8051, ARM Cortex-M use Harvard architecture**

### Interview One-Liner:

> "Von Neumann uses single memory for code and data, while Harvard uses
> separate memories, enabling faster execution."

------------------------------------------------------------------------

## 3. MCU Architecture (Block Level)

    +-----------------------+
    |        CPU            |
    |  (ALU, Registers, PC) |
    +----------+------------+
               |
    +----------v------------+
    |      System Bus       |
    +----+-----------+------+
         |           |
    +----v----+  +---v-----+
    |  Flash  |  |  SRAM   |
    +---------+  +---------+
         |
    +----v------------------+
    |     Peripherals       |
    | GPIO, UART, SPI, I2C  |
    | Timers, ADC           |
    +-----------------------+

------------------------------------------------------------------------

## 4. 8051 Microcontroller Architecture (IMPORTANT 🔥)

### Key Features of 8051:

-   8-bit CPU
-   Harvard architecture
-   On-chip peripherals
-   Widely used in teaching & interviews

------------------------------------------------------------------------

### 8051 Memory Architecture

#### Program Memory (Code)

-   On-chip ROM / Flash (typically 4 KB)
-   External program memory supported (up to 64 KB)

#### Data Memory

-   Internal RAM: 128 bytes
-   External RAM: up to 64 KB


    Code Memory  → Instructions
    Data Memory  → Variables

------------------------------------------------------------------------

### 8051 Internal RAM Structure (128 Bytes)

  Address Range   Usage
  --------------- ---------------------
  00H--1FH        Register Banks
  20H--2FH        Bit-addressable RAM
  30H--7FH        General RAM

------------------------------------------------------------------------

### Special Function Registers (SFRs)

-   Control peripherals
-   Address range: **80H--FFH**
-   Examples:
    -   P0, P1, P2, P3
    -   TMOD, TCON
    -   SCON, SBUF

📌 SFRs are **memory-mapped**

------------------------------------------------------------------------

## 5. Boot Sequence (Generic MCU)

    Power ON
      ↓
    Reset
      ↓
    Reset Vector
      ↓
    Startup Code
      ↓
    main()

### Reset Vector

-   Fixed memory location
-   First instruction executed after reset

------------------------------------------------------------------------

## 6. Clock Architecture

### Clock in 8051:

-   External crystal oscillator
-   Typical: **11.0592 MHz** (UART friendly)

### Machine Cycle:

-   12 oscillator cycles = 1 machine cycle

------------------------------------------------------------------------

## 7. Interrupt Architecture

### 8051 Interrupt Sources:

-   External Interrupt 0
-   Timer 0
-   External Interrupt 1
-   Timer 1
-   Serial Interrupt

### Interrupt Flow:

    Interrupt → Context Save → ISR → RETI → Resume

📌 Interrupt vectors are **fixed addresses** in code memory

------------------------------------------------------------------------

## 8. GPIO Architecture (8051)

-   4 Ports: **P0, P1, P2, P3**
-   Each port is 8-bit

### Port Characteristics:

-   P0: Open-drain (needs pull-up)
-   P1: Internal pull-up
-   P2: Internal pull-up
-   P3: Alternate functions

------------------------------------------------------------------------

## 9. Memory-Mapped I/O

-   Peripherals controlled via registers
-   Registers accessed like memory

``` c
sfr P1 = 0x90;   // Example
```

------------------------------------------------------------------------

## 10. Embedded C & MCU Notes

-   Infinite loop using `while(1)`
-   Stack stored in internal RAM
-   Avoid recursion in 8051 (small stack)
-   ISRs must end with `RETI`

------------------------------------------------------------------------

## 11. Interview One-Liners (🔥)

-   "8051 follows Harvard architecture."
-   "Program and data memory are separate in 8051."
-   "Von Neumann uses single memory, Harvard uses separate."
-   "P0 is open-drain, requires pull-up."
-   "SFRs control peripherals in 8051."

------------------------------------------------------------------------

## Final Summary

8051 is an 8-bit microcontroller based on **Harvard architecture**, with
separate program and data memory. It uses fixed interrupt vectors,
external clock input, and memory-mapped SFRs to control peripherals.
Understanding Harvard vs Von Neumann architecture is critical for
embedded interviews.

------------------------------------------------------------------------


Architecture (8051)

“The 8051 is an 8-bit microcontroller based on Harvard architecture.
It has separate program and data memory.
It contains 4 KB on-chip ROM, 128 bytes of internal RAM, 4 parallel I/O ports, 2 timers, and 5 interrupt sources.
Peripherals are controlled using Special Function Registers (SFRs).
It also supports external program and data memory.”

Transistion into morder MCU

“In my current role, my work did not involve direct microcontroller programming, but it was still in the embedded domain.
During my college days, I worked on the 8051 microcontroller, where I implemented GPIO, timers, interrupts, and basic UART.
I’ve kept my fundamentals strong, and MCU concepts like interrupts, memory, and peripherals are common across platforms.
I’m confident I can quickly adapt to modern MCUs.”

You said 8051 follows Harvard architecture.
Then how does the CPU access data stored in program memory?

“8051 is based on Harvard architecture, so program and data memory are separate.
However, constants stored in program memory can be accessed using the MOVC instruction.”

“Port 0 of 8051 is an open-drain port, so it cannot drive logic HIGH by itself.
Therefore, it requires an external pull-up resistor to get a HIGH level.”

You have not worked on microcontrollers in your corporate role.
How confident are you that you can start contributing on a modern MCU project within a short time?

“Although my current project did not involve direct microcontroller programming, my fundamentals are strong from working with the 8051.
Core concepts like GPIO, interrupts, timers, memory, and clocks are common across all MCUs.
My approach is to understand the architecture and reference manual of the target MCU and start with small tasks like GPIO and timers.
Because of this, I’m confident I can start contributing on a modern MCU within a short time.”
