/*
 * Copyright (c) 2006, 2007 Advanced Micro Devices, Inc.
 * Contributed by Ray Bryant <raybry@mpdtxmail.amd.com> 
 * Contributed by Robert Richter <robert.richter@amd.com>
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies
 * of the Software, and to permit persons to whom the Software is furnished to do so,
 * subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED,
 * INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A
 * PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT
 * HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF
 * CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE
 * OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 *
 * This file is part of libpfm, a performance monitoring support library for
 * applications on Linux.
 */

/* History
 *
 * Feb 10 2006 -- Ray Bryant, raybry@mpdtxmail.amd.com
 *
 * Brought event table up-to-date with the 3.85 (October 2005) version of the
 * "BIOS and Kernel Developer's Guide for the AMD Athlon[tm] 64 and
 * AMD Opteron[tm] Processors," AMD Publication # 26094.
 * 
 * Dec 12 2007 -- Robert Richter, robert.richter@amd.com
 *
 * Updated to: BIOS and Kernel Developer's Guide for AMD NPT Family
 * 0Fh Processors, Publication # 32559, Revision: 3.08, Issue Date:
 * July 2007
 * 
 * Feb 26 2009 -- Robert Richter, robert.richter@amd.com
 *
 * Updates and fixes of some revision flags and descriptions according
 * to these documents:
 * BIOS and Kernel Developer's Guide, #26094, Revision: 3.30
 * BIOS and Kernel Developer's Guide, #32559, Revision: 3.12
 */

static const amd64_entry_t amd64_k8_pe[]={
/*  0 */{.name = "DISPATCHED_FPU",
	.code  = 0x00,
	.modmsk = AMD64_BASIC_ATTRS,
	.desc  = "Dispatched FPU Operations",
	.ngrp = 1,
	.numasks = 7,
	.umasks  = {
		{ .uname = "OPS_ADD",
		  .udesc = "Add pipe ops",
		  .ucode = 0x01,
		},
		{ .uname = "OPS_MULTIPLY",
		  .udesc = "Multiply pipe ops",
		  .ucode = 0x02,
		},
		{ .uname = "OPS_STORE",
		  .udesc = "Store pipe ops",
		  .ucode = 0x04,
		},
		{ .uname = "OPS_ADD_PIPE_LOAD_OPS",
		  .udesc = "Add pipe load ops",
		  .ucode = 0x08,
		},
		{ .uname = "OPS_MULTIPLY_PIPE_LOAD_OPS",
		  .udesc = "Multiply pipe load ops",
		  .ucode = 0x10,
		},
		{ .uname = "OPS_STORE_PIPE_LOAD_OPS",
		  .udesc = "Store pipe load ops",
		  .ucode = 0x20,
		},
		{ .uname = "ALL",
		  .udesc = "All sub-events selected",
		  .ucode = 0x3F,
		  .uflags = AMD64_FL_DFL|AMD64_FL_NCOMBO,
		},
	 },
	},
/*  1 */{.name = "CYCLES_NO_FPU_OPS_RETIRED",
	.code  = 0x01,
	.modmsk = AMD64_BASIC_ATTRS,
	.desc  = "Cycles with no FPU Ops Retired",
	},
/*  2 */{.name = "DISPATCHED_FPU_OPS_FAST_FLAG",
	.code  = 0x02,
	.modmsk = AMD64_BASIC_ATTRS,
	.desc  = "Dispatched Fast Flag FPU Operations",
	},
/*  3 */{.name = "SEGMENT_REGISTER_LOADS",
	.code  = 0x20,
	.modmsk = AMD64_BASIC_ATTRS,
	.desc  = "Segment Register Loads",
	.ngrp = 1,
	.numasks = 8,
	.umasks  = {
		{ .uname = "ES",
		  .udesc = "ES",
		  .ucode = 0x01,
		},
		{ .uname = "CS",
		  .udesc = "CS",
		  .ucode = 0x02,
		},
		{ .uname = "SS",
		  .udesc = "SS",
		  .ucode = 0x04,
		},
		{ .uname = "DS",
		  .udesc = "DS",
		  .ucode = 0x08,
		},
		{ .uname = "FS",
		  .udesc = "FS",
		  .ucode = 0x10,
		},
		{ .uname = "GS",
		  .udesc = "GS",
		  .ucode = 0x20,
		},
		{ .uname = "HS",
		  .udesc = "HS",
		  .ucode = 0x40,
		},
		{ .uname = "ALL",
		  .udesc = "All segments",
		  .ucode = 0x7F,
		  .uflags = AMD64_FL_DFL|AMD64_FL_NCOMBO,
		},
	 },
	},
/*  4 */{.name = "PIPELINE_RESTART_DUE_TO_SELF_MODIFYING_CODE",
	.code  = 0x21,
	.modmsk = AMD64_BASIC_ATTRS,
	.desc  = "Pipeline restart due to self-modifying code",
	},
/*  5 */{.name = "PIPELINE_RESTART_DUE_TO_PROBE_HIT",
	.code  = 0x22,
	.modmsk = AMD64_BASIC_ATTRS,
	.desc  = "Pipeline restart due to probe hit",
	},
/*  6 */{.name = "LS_BUFFER_2_FULL_CYCLES",
	.code  = 0x23,
	.modmsk = AMD64_BASIC_ATTRS,
	.desc  = "LS Buffer 2 Full",
	},
/*  7 */{.name = "LOCKED_OPS",
	.code  = 0x24,
	.modmsk = AMD64_BASIC_ATTRS,
	.desc  = "Locked Operations",
	.ngrp = 1,
	.numasks = 4,
	.umasks  = {
		{ .uname = "EXECUTED",
		  .udesc = "The number of locked instructions executed",
		  .ucode = 0x01,
		},
		{ .uname = "CYCLES_SPECULATIVE_PHASE",
		  .udesc = "The number of cycles spent in speculative phase",
		  .ucode = 0x02,
		},
		{ .uname = "CYCLES_NON_SPECULATIVE_PHASE",
		  .udesc = "The number of cycles spent in non-speculative phase (including cache miss penalty)",
		  .ucode = 0x04,
		},
		{ .uname = "ALL",
		  .udesc = "All sub-events selected",
		  .ucode = 0x07,
		  .uflags = AMD64_FL_DFL|AMD64_FL_NCOMBO,
		},
	 },
	},
/*  8 */{.name = "MEMORY_REQUESTS",
	.code  = 0x65,
	.modmsk = AMD64_BASIC_ATTRS,
	.desc  = "Memory Requests by Type",
	.ngrp = 1,
	.numasks = 4,
	.umasks  = {
		{ .uname = "NON_CACHEABLE",
		  .udesc = "Requests to non-cacheable (UC) memory",
		  .ucode = 0x01,
		},
		{ .uname = "WRITE_COMBINING",
		  .udesc = "Requests to write-combining (WC) memory or WC buffer flushes to WB memory",
		  .ucode = 0x02,
		},
		{ .uname = "STREAMING_STORE",
		  .udesc = "Streaming store (SS) requests",
		  .ucode = 0x80,
		},
		{ .uname = "ALL",
		  .udesc = "All sub-events selected",
		  .ucode = 0x83,
		  .uflags = AMD64_FL_DFL|AMD64_FL_NCOMBO,
		},
	 },
	},
/*  9 */{.name = "DATA_CACHE_ACCESSES",
	.code  = 0x40,
	.modmsk = AMD64_BASIC_ATTRS,
	.desc  = "Data Cache Accesses",
	},
/* 10 */{.name = "DATA_CACHE_MISSES",
	.code  = 0x41,
	.modmsk = AMD64_BASIC_ATTRS,
	.desc  = "Data Cache Misses",
	},
/* 11 */{.name = "DATA_CACHE_REFILLS",
	.code  = 0x42,
	.modmsk = AMD64_BASIC_ATTRS,
	.desc  = "Data Cache Refills from L2 or System",
	.ngrp = 1,
	.numasks = 6,
	.umasks  = {
		{ .uname = "SYSTEM",
		  .udesc = "Refill from System",
		  .ucode = 0x01,
		},
		{ .uname = "L2_SHARED",
		  .udesc = "Shared-state line from L2",
		  .ucode = 0x02,
		},
		{ .uname = "L2_EXCLUSIVE",
		  .udesc = "Exclusive-state line from L2",
		  .ucode = 0x04,
		},
		{ .uname = "L2_OWNED",
		  .udesc = "Owned-state line from L2",
		  .ucode = 0x08,
		},
		{ .uname = "L2_MODIFIED",
		  .udesc = "Modified-state line from L2",
		  .ucode = 0x10,
		},
		{ .uname = "ALL",
		  .udesc = "Shared, Exclusive, Owned, Modified State Refills",
		  .ucode = 0x1F,
		  .uflags = AMD64_FL_DFL|AMD64_FL_NCOMBO,
		},
	 },
	},
/* 12 */{.name = "DATA_CACHE_REFILLS_FROM_SYSTEM",
	.code  = 0x43,
	.modmsk = AMD64_BASIC_ATTRS,
	.desc  = "Data Cache Refills from System",
	.ngrp = 1,
	.numasks = 6,
	.umasks  = {
		{ .uname = "INVALID",
		  .udesc = "Invalid",
		  .ucode = 0x01,
		},
		{ .uname = "SHARED",
		  .udesc = "Shared",
		  .ucode = 0x02,
		},
		{ .uname = "EXCLUSIVE",
		  .udesc = "Exclusive",
		  .ucode = 0x04,
		},
		{ .uname = "OWNED",
		  .udesc = "Owned",
		  .ucode = 0x08,
		},
		{ .uname = "MODIFIED",
		  .udesc = "Modified",
		  .ucode = 0x10,
		},
		{ .uname = "ALL",
		  .udesc = "Invalid, Shared, Exclusive, Owned, Modified",
		  .ucode = 0x1F,
		  .uflags = AMD64_FL_DFL|AMD64_FL_NCOMBO,
		},
	 },
	},
/* 13 */{.name = "DATA_CACHE_LINES_EVICTED",
	.code  = 0x44,
	.modmsk = AMD64_BASIC_ATTRS,
	.desc  = "Data Cache Lines Evicted",
	.ngrp = 1,
	.numasks = 6,
	.umasks  = {
		{ .uname = "INVALID",
		  .udesc = "Invalid",
		  .ucode = 0x01,
		},
		{ .uname = "SHARED",
		  .udesc = "Shared",
		  .ucode = 0x02,
		},
		{ .uname = "EXCLUSIVE",
		  .udesc = "Exclusive",
		  .ucode = 0x04,
		},
		{ .uname = "OWNED",
		  .udesc = "Owned",
		  .ucode = 0x08,
		},
		{ .uname = "MODIFIED",
		  .udesc = "Modified",
		  .ucode = 0x10,
		},
		{ .uname = "ALL",
		  .udesc = "Invalid, Shared, Exclusive, Owned, Modified",
		  .ucode = 0x1F,
		  .uflags = AMD64_FL_DFL|AMD64_FL_NCOMBO,
		},
	 },
	},
/* 14 */{.name = "L1_DTLB_MISS_AND_L2_DTLB_HIT",
	.code  = 0x45,
	.modmsk = AMD64_BASIC_ATTRS,
	.desc  = "L1 DTLB Miss and L2 DTLB Hit",
	},
/* 15 */{.name = "L1_DTLB_AND_L2_DTLB_MISS",
	.code  = 0x46,
	.modmsk = AMD64_BASIC_ATTRS,
	.desc  = "L1 DTLB and L2 DTLB Miss",
	},
/* 16 */{.name = "MISALIGNED_ACCESSES",
	.code  = 0x47,
	.modmsk = AMD64_BASIC_ATTRS,
	.desc  = "Misaligned Accesses",
	},
/* 17 */{.name = "MICROARCHITECTURAL_LATE_CANCEL_OF_AN_ACCESS",
	.code  = 0x48,
	.modmsk = AMD64_BASIC_ATTRS,
	.desc  = "Microarchitectural Late Cancel of an Access",
	},
/* 18 */{.name = "MICROARCHITECTURAL_EARLY_CANCEL_OF_AN_ACCESS",
	.code  = 0x49,
	.modmsk = AMD64_BASIC_ATTRS,
	.desc  = "Microarchitectural Early Cancel of an Access",
	},
/* 19 */{.name = "SCRUBBER_SINGLE_BIT_ECC_ERRORS",
	.code  = 0x4A,
	.modmsk = AMD64_BASIC_ATTRS,
	.desc  = "Single-bit ECC Errors Recorded by Scrubber",
	.ngrp = 1,
	.numasks = 3,
	.umasks  = {
		{ .uname = "SCRUBBER_ERROR",
		  .udesc = "Scrubber error",
		  .ucode = 0x01,
		},
		{ .uname = "PIGGYBACK_ERROR",
		  .udesc = "Piggyback scrubber errors",
		  .ucode = 0x02,
		},
		{ .uname = "ALL",
		  .udesc = "All sub-events selected",
		  .ucode = 0x03,
		  .uflags = AMD64_FL_DFL|AMD64_FL_NCOMBO,
		},
	 },
	},
/* 20 */{.name = "PREFETCH_INSTRUCTIONS_DISPATCHED",
	.code  = 0x4B,
	.modmsk = AMD64_BASIC_ATTRS,
	.desc  = "Prefetch Instructions Dispatched",
	.ngrp = 1,
	.numasks = 4,
	.umasks  = {
		{ .uname = "LOAD",
		  .udesc = "Load (Prefetch, PrefetchT0/T1/T2)",
		  .ucode = 0x01,
		},
		{ .uname = "STORE",
		  .udesc = "Store (PrefetchW)",
		  .ucode = 0x02,
		},
		{ .uname = "NTA",
		  .udesc = "NTA (PrefetchNTA)",
		  .ucode = 0x04,
		},
		{ .uname = "ALL",
		  .udesc = "All sub-events selected",
		  .ucode = 0x07,
		  .uflags = AMD64_FL_DFL|AMD64_FL_NCOMBO,
		},
	 },
	},
/* 21 */{.name = "DCACHE_MISSES_BY_LOCKED_INSTRUCTIONS",
	.code  = 0x4C,
	.modmsk = AMD64_BASIC_ATTRS,
	.desc  = "DCACHE Misses by Locked Instructions",
	.ngrp = 1,
	.numasks = 2,
	.umasks  = {
		{ .uname = "DATA_CACHE_MISSES_BY_LOCKED_INSTRUCTIONS",
		  .udesc = "Data cache misses by locked instructions",
		  .ucode = 0x02,
		},
		{ .uname = "ALL",
		  .udesc = "All sub-events selected",
		  .ucode = 0x02,
		  .uflags = AMD64_FL_DFL|AMD64_FL_NCOMBO,
		},
	 },
	},
/* 22 */{.name = "DATA_PREFETCHES",
	.code  = 0x67,
	.modmsk = AMD64_BASIC_ATTRS,
	.desc  = "Data Prefetcher",
	.ngrp = 1,
	.numasks = 3,
	.umasks  = {
		{ .uname = "CANCELLED",
		  .udesc = "Cancelled prefetches",
		  .ucode = 0x01,
		},
		{ .uname = "ATTEMPTED",
		  .udesc = "Prefetch attempts",
		  .ucode = 0x02,
		},
		{ .uname = "ALL",
		  .udesc = "All sub-events selected",
		  .ucode = 0x03,
		  .uflags = AMD64_FL_DFL|AMD64_FL_NCOMBO,
		},
	 },
	},
/* 23 */{.name = "SYSTEM_READ_RESPONSES",
	.code  = 0x6C,
	.modmsk = AMD64_BASIC_ATTRS,
	.desc  = "System Read Responses by Coherency State",
	.ngrp = 1,
	.numasks = 4,
	.umasks  = {
		{ .uname = "EXCLUSIVE",
		  .udesc = "Exclusive",
		  .ucode = 0x01,
		},
		{ .uname = "MODIFIED",
		  .udesc = "Modified",
		  .ucode = 0x02,
		},
		{ .uname = "SHARED",
		  .udesc = "Shared",
		  .ucode = 0x04,
		},
		{ .uname = "ALL",
		  .udesc = "Exclusive, Modified, Shared",
		  .ucode = 0x07,
		  .uflags = AMD64_FL_DFL|AMD64_FL_NCOMBO,
		},
	 },
	},
/* 24 */{.name = "QUADWORDS_WRITTEN_TO_SYSTEM",
	.code  = 0x6D,
	.modmsk = AMD64_BASIC_ATTRS,
	.desc  = "Quadwords Written to System",
	.ngrp = 1,
	.numasks = 2,
	.umasks  = {
		{ .uname = "QUADWORD_WRITE_TRANSFER",
		  .udesc = "Quadword write transfer",
		  .ucode = 0x01,
		},
		{ .uname = "ALL",
		  .udesc = "All sub-events selected",
		  .ucode = 0x01,
		  .uflags = AMD64_FL_DFL|AMD64_FL_NCOMBO,
		},
	 },
	},
/* 25 */{.name = "REQUESTS_TO_L2",
	.code  = 0x7D,
	.modmsk = AMD64_BASIC_ATTRS,
	.desc  = "Requests to L2 Cache",
	.ngrp = 1,
	.numasks = 6,
	.umasks  = {
		{ .uname = "INSTRUCTIONS",
		  .udesc = "IC fill",
		  .ucode = 0x01,
		},
		{ .uname = "DATA",
		  .udesc = "DC fill",
		  .ucode = 0x02,
		},
		{ .uname = "TLB_WALK",
		  .udesc = "TLB fill (page table walks)",
		  .ucode = 0x04,
		},
		{ .uname = "SNOOP",
		  .udesc = "Tag snoop request",
		  .ucode = 0x08,
		},
		{ .uname = "CANCELLED",
		  .udesc = "Cancelled request",
		  .ucode = 0x10,
		},
		{ .uname = "ALL",
		  .udesc = "All non-cancelled requests",
		  .ucode = 0x1F,
		  .uflags = AMD64_FL_DFL|AMD64_FL_NCOMBO,
		},
	 },
	},
/* 26 */{.name = "L2_CACHE_MISS",
	.code  = 0x7E,
	.modmsk = AMD64_BASIC_ATTRS,
	.desc  = "L2 Cache Misses",
	.ngrp = 1,
	.numasks = 4,
	.umasks  = {
		{ .uname = "INSTRUCTIONS",
		  .udesc = "IC fill",
		  .ucode = 0x01,
		},
		{ .uname = "DATA",
		  .udesc = "DC fill (includes possible replays, whereas event 41h does not)",
		  .ucode = 0x02,
		},
		{ .uname = "TLB_WALK",
		  .udesc = "TLB page table walk",
		  .ucode = 0x04,
		},
		{ .uname = "ALL",
		  .udesc = "Instructions, Data, TLB walk",
		  .ucode = 0x07,
		  .uflags = AMD64_FL_DFL|AMD64_FL_NCOMBO,
		},
	 },
	},
/* 27 */{.name = "L2_FILL_WRITEBACK",
	.code  = 0x7F,
	.modmsk = AMD64_BASIC_ATTRS,
	.desc  = "L2 Fill/Writeback",
	.ngrp = 1,
	.numasks = 4,
	.umasks  = {
		{ .uname = "L2_FILLS",
		  .udesc = "L2 fills (victims from L1 caches, TLB page table walks and data prefetches)",
		  .ucode = 0x01,
		},
		{ .uname = "ALL",
		  .udesc = "All sub-events selected",
		  .ucode = 0x01,
		  .uflags = AMD64_FL_TILL_K8_REV_E|AMD64_FL_DFL|AMD64_FL_NCOMBO,
		},
		{ .uname = "L2_WRITEBACKS",
		  .udesc = "L2 Writebacks to system.",
		  .ucode = 0x02,
		  .uflags = AMD64_FL_K8_REV_F,
		},
		{ .uname = "ALL",
		  .udesc = "All sub-events selected",
		  .ucode = 0x03,
		  .uflags = AMD64_FL_K8_REV_F|AMD64_FL_DFL|AMD64_FL_NCOMBO,
		},
	 },
	},
/* 28 */{.name = "INSTRUCTION_CACHE_FETCHES",
	.code  = 0x80,
	.modmsk = AMD64_BASIC_ATTRS,
	.desc  = "Instruction Cache Fetches",
	},
/* 29 */{.name = "INSTRUCTION_CACHE_MISSES",
	.code  = 0x81,
	.modmsk = AMD64_BASIC_ATTRS,
	.desc  = "Instruction Cache Misses",
	},
/* 30 */{.name = "INSTRUCTION_CACHE_REFILLS_FROM_L2",
	.code  = 0x82,
	.modmsk = AMD64_BASIC_ATTRS,
	.desc  = "Instruction Cache Refills from L2",
	},
/* 31 */{.name = "INSTRUCTION_CACHE_REFILLS_FROM_SYSTEM",
	.code  = 0x83,
	.modmsk = AMD64_BASIC_ATTRS,
	.desc  = "Instruction Cache Refills from System",
	},
/* 32 */{.name = "L1_ITLB_MISS_AND_L2_ITLB_HIT",
	.code  = 0x84,
	.modmsk = AMD64_BASIC_ATTRS,
	.desc  = "L1 ITLB Miss and L2 ITLB Hit",
	},
/* 33 */{.name = "L1_ITLB_MISS_AND_L2_ITLB_MISS",
	.code  = 0x85,
	.modmsk = AMD64_BASIC_ATTRS,
	.desc  = "L1 ITLB Miss and L2 ITLB Miss",
	},
/* 34 */{.name = "PIPELINE_RESTART_DUE_TO_INSTRUCTION_STREAM_PROBE",
	.code  = 0x86,
	.modmsk = AMD64_BASIC_ATTRS,
	.desc  = "Pipeline Restart Due to Instruction Stream Probe",
	},
/* 35 */{.name = "INSTRUCTION_FETCH_STALL",
	.code  = 0x87,
	.modmsk = AMD64_BASIC_ATTRS,
	.desc  = "Instruction Fetch Stall",
	},
/* 36 */{.name = "RETURN_STACK_HITS",
	.code  = 0x88,
	.modmsk = AMD64_BASIC_ATTRS,
	.desc  = "Return Stack Hits",
	},
/* 37 */{.name = "RETURN_STACK_OVERFLOWS",
	.code  = 0x89,
	.modmsk = AMD64_BASIC_ATTRS,
	.desc  = "Return Stack Overflows",
	},
/* 38 */{.name = "RETIRED_CLFLUSH_INSTRUCTIONS",
	.code  = 0x26,
	.modmsk = AMD64_BASIC_ATTRS,
	.desc  = "Retired CLFLUSH Instructions",
	},
/* 39 */{.name = "RETIRED_CPUID_INSTRUCTIONS",
	.code  = 0x27,
	.modmsk = AMD64_BASIC_ATTRS,
	.desc  = "Retired CPUID Instructions",
	},
/* 40 */{.name = "CPU_CLK_UNHALTED",
	.code  = 0x76,
	.modmsk = AMD64_BASIC_ATTRS,
	.desc  = "CPU Clocks not Halted",
	},
/* 41 */{.name = "RETIRED_INSTRUCTIONS",
	.code  = 0xC0,
	.modmsk = AMD64_BASIC_ATTRS,
	.desc  = "Retired Instructions",
	},
/* 42 */{.name = "RETIRED_UOPS",
	.code  = 0xC1,
	.modmsk = AMD64_BASIC_ATTRS,
	.desc  = "Retired uops",
	},
/* 43 */{.name = "RETIRED_BRANCH_INSTRUCTIONS",
	.code  = 0xC2,
	.modmsk = AMD64_BASIC_ATTRS,
	.desc  = "Retired Branch Instructions",
	},
/* 44 */{.name = "RETIRED_MISPREDICTED_BRANCH_INSTRUCTIONS",
	.code  = 0xC3,
	.modmsk = AMD64_BASIC_ATTRS,
	.desc  = "Retired Mispredicted Branch Instructions",
	},
/* 45 */{.name = "RETIRED_TAKEN_BRANCH_INSTRUCTIONS",
	.code  = 0xC4,
	.modmsk = AMD64_BASIC_ATTRS,
	.desc  = "Retired Taken Branch Instructions",
	},
/* 46 */{.name = "RETIRED_TAKEN_BRANCH_INSTRUCTIONS_MISPREDICTED",
	.code  = 0xC5,
	.modmsk = AMD64_BASIC_ATTRS,
	.desc  = "Retired Taken Branch Instructions Mispredicted",
	},
/* 47 */{.name = "RETIRED_FAR_CONTROL_TRANSFERS",
	.code  = 0xC6,
	.modmsk = AMD64_BASIC_ATTRS,
	.desc  = "Retired Far Control Transfers",
	},
/* 48 */{.name = "RETIRED_BRANCH_RESYNCS",
	.code  = 0xC7,
	.modmsk = AMD64_BASIC_ATTRS,
	.desc  = "Retired Branch Resyncs",
	},
/* 49 */{.name = "RETIRED_NEAR_RETURNS",
	.code  = 0xC8,
	.modmsk = AMD64_BASIC_ATTRS,
	.desc  = "Retired Near Returns",
	},
/* 50 */{.name = "RETIRED_NEAR_RETURNS_MISPREDICTED",
	.code  = 0xC9,
	.modmsk = AMD64_BASIC_ATTRS,
	.desc  = "Retired Near Returns Mispredicted",
	},
/* 51 */{.name = "RETIRED_INDIRECT_BRANCHES_MISPREDICTED",
	.code  = 0xCA,
	.modmsk = AMD64_BASIC_ATTRS,
	.desc  = "Retired Indirect Branches Mispredicted",
	},
/* 52 */{.name = "RETIRED_MMX_AND_FP_INSTRUCTIONS",
	.code  = 0xCB,
	.modmsk = AMD64_BASIC_ATTRS,
	.desc  = "Retired MMX/FP Instructions",
	.ngrp = 1,
	.numasks = 5,
	.umasks  = {
		{ .uname = "X87",
		  .udesc = "x87 instructions",
		  .ucode = 0x01,
		},
		{ .uname = "MMX_AND_3DNOW",
		  .udesc = "MMX and 3DNow! instructions",
		  .ucode = 0x02,
		},
		{ .uname = "PACKED_SSE_AND_SSE2",
		  .udesc = "Packed SSE and SSE2 instructions",
		  .ucode = 0x04,
		},
		{ .uname = "SCALAR_SSE_AND_SSE2",
		  .udesc = "Scalar SSE and SSE2 instructions",
		  .ucode = 0x08,
		},
		{ .uname = "ALL",
		  .udesc = "X87, MMX(TM), 3DNow!(TM), Scalar and Packed SSE and SSE2 instructions",
		  .ucode = 0x0F,
		  .uflags = AMD64_FL_DFL|AMD64_FL_NCOMBO,
		},
	 },
	},
/* 53 */{.name = "RETIRED_FASTPATH_DOUBLE_OP_INSTRUCTIONS",
	.code  = 0xCC,
	.modmsk = AMD64_BASIC_ATTRS,
	.desc  = "Retired Fastpath Double Op Instructions",
	.ngrp = 1,
	.numasks = 4,
	.umasks  = {
		{ .uname = "POSITION_0",
		  .udesc = "With low op in position 0",
		  .ucode = 0x01,
		},
		{ .uname = "POSITION_1",
		  .udesc = "With low op in position 1",
		  .ucode = 0x02,
		},
		{ .uname = "POSITION_2",
		  .udesc = "With low op in position 2",
		  .ucode = 0x04,
		},
		{ .uname = "ALL",
		  .udesc = "With low op in position 0, 1, or 2",
		  .ucode = 0x07,
		  .uflags = AMD64_FL_DFL|AMD64_FL_NCOMBO,
		},
	 },
	},
/* 54 */{.name = "INTERRUPTS_MASKED_CYCLES",
	.code  = 0xCD,
	.modmsk = AMD64_BASIC_ATTRS,
	.desc  = "Interrupts-Masked Cycles",
	},
/* 55 */{.name = "INTERRUPTS_MASKED_CYCLES_WITH_INTERRUPT_PENDING",
	.code  = 0xCE,
	.modmsk = AMD64_BASIC_ATTRS,
	.desc  = "Interrupts-Masked Cycles with Interrupt Pending",
	},
/* 56 */{.name = "INTERRUPTS_TAKEN",
	.code  = 0xCF,
	.modmsk = AMD64_BASIC_ATTRS,
	.desc  = "Interrupts Taken",
	},
/* 57 */{.name = "DECODER_EMPTY",
	.code  = 0xD0,
	.modmsk = AMD64_BASIC_ATTRS,
	.desc  = "Decoder Empty",
	},
/* 58 */{.name = "DISPATCH_STALLS",
	.code  = 0xD1,
	.modmsk = AMD64_BASIC_ATTRS,
	.desc  = "Dispatch Stalls",
	},
/* 59 */{.name = "DISPATCH_STALL_FOR_BRANCH_ABORT",
	.code  = 0xD2,
	.modmsk = AMD64_BASIC_ATTRS,
	.desc  = "Dispatch Stall for Branch Abort to Retire",
	},
/* 60 */{.name = "DISPATCH_STALL_FOR_SERIALIZATION",
	.code  = 0xD3,
	.modmsk = AMD64_BASIC_ATTRS,
	.desc  = "Dispatch Stall for Serialization",
	},
/* 61 */{.name = "DISPATCH_STALL_FOR_SEGMENT_LOAD",
	.code  = 0xD4,
	.modmsk = AMD64_BASIC_ATTRS,
	.desc  = "Dispatch Stall for Segment Load",
	},
/* 62 */{.name = "DISPATCH_STALL_FOR_REORDER_BUFFER_FULL",
	.code  = 0xD5,
	.modmsk = AMD64_BASIC_ATTRS,
	.desc  = "Dispatch Stall for Reorder Buffer Full",
	},
/* 63 */{.name = "DISPATCH_STALL_FOR_RESERVATION_STATION_FULL",
	.code  = 0xD6,
	.modmsk = AMD64_BASIC_ATTRS,
	.desc  = "Dispatch Stall for Reservation Station Full",
	},
/* 64 */{.name = "DISPATCH_STALL_FOR_FPU_FULL",
	.code  = 0xD7,
	.modmsk = AMD64_BASIC_ATTRS,
	.desc  = "Dispatch Stall for FPU Full",
	},
/* 65 */{.name = "DISPATCH_STALL_FOR_LS_FULL",
	.code  = 0xD8,
	.modmsk = AMD64_BASIC_ATTRS,
	.desc  = "Dispatch Stall for LS Full",
	},
/* 66 */{.name = "DISPATCH_STALL_WAITING_FOR_ALL_QUIET",
	.code  = 0xD9,
	.modmsk = AMD64_BASIC_ATTRS,
	.desc  = "Dispatch Stall Waiting for All Quiet",
	},
/* 67 */{.name = "DISPATCH_STALL_FOR_FAR_TRANSFER_OR_RSYNC",
	.code  = 0xDA,
	.modmsk = AMD64_BASIC_ATTRS,
	.desc  = "Dispatch Stall for Far Transfer or Resync to Retire",
	},
/* 68 */{.name = "FPU_EXCEPTIONS",
	.code  = 0xDB,
	.modmsk = AMD64_BASIC_ATTRS,
	.desc  = "FPU Exceptions",
	.ngrp = 1,
	.numasks = 5,
	.umasks  = {
		{ .uname = "X87_RECLASS_MICROFAULTS",
		  .udesc = "x87 reclass microfaults",
		  .ucode = 0x01,
		},
		{ .uname = "SSE_RETYPE_MICROFAULTS",
		  .udesc = "SSE retype microfaults",
		  .ucode = 0x02,
		},
		{ .uname = "SSE_RECLASS_MICROFAULTS",
		  .udesc = "SSE reclass microfaults",
		  .ucode = 0x04,
		},
		{ .uname = "SSE_AND_X87_MICROTRAPS",
		  .udesc = "SSE and x87 microtraps",
		  .ucode = 0x08,
		},
		{ .uname = "ALL",
		  .udesc = "All sub-events selected",
		  .ucode = 0x0F,
		  .uflags = AMD64_FL_DFL|AMD64_FL_NCOMBO,
		},
	 },
	},
/* 69 */{.name = "DR0_BREAKPOINT_MATCHES",
	.code  = 0xDC,
	.modmsk = AMD64_BASIC_ATTRS,
	.desc  = "DR0 Breakpoint Matches",
	},
/* 70 */{.name = "DR1_BREAKPOINT_MATCHES",
	.code  = 0xDD,
	.modmsk = AMD64_BASIC_ATTRS,
	.desc  = "DR1 Breakpoint Matches",
	},
/* 71 */{.name = "DR2_BREAKPOINT_MATCHES",
	.code  = 0xDE,
	.modmsk = AMD64_BASIC_ATTRS,
	.desc  = "DR2 Breakpoint Matches",
	},
/* 72 */{.name = "DR3_BREAKPOINT_MATCHES",
	.code  = 0xDF,
	.modmsk = AMD64_BASIC_ATTRS,
	.desc  = "DR3 Breakpoint Matches",
	},
/* 73 */{.name = "DRAM_ACCESSES_PAGE",
	.code  = 0xE0,
	.modmsk = AMD64_BASIC_ATTRS,
	.desc  = "DRAM Accesses",
	.ngrp = 1,
	.numasks = 4,
	.umasks  = {
		{ .uname = "HIT",
		  .udesc = "Page hit",
		  .ucode = 0x01,
		},
		{ .uname = "MISS",
		  .udesc = "Page Miss",
		  .ucode = 0x02,
		},
		{ .uname = "CONFLICT",
		  .udesc = "Page Conflict",
		  .ucode = 0x04,
		},
		{ .uname = "ALL",
		  .udesc = "Page Hit, Miss, or Conflict",
		  .ucode = 0x07,
		  .uflags = AMD64_FL_DFL|AMD64_FL_NCOMBO,
		},
	 },
	},
/* 74 */{.name = "MEMORY_CONTROLLER_PAGE_TABLE_OVERFLOWS",
	.code  = 0xE1,
	.modmsk = AMD64_BASIC_ATTRS,
	.desc  = "Memory Controller Page Table Overflows",
	},
/* 75 */{.name = "MEMORY_CONTROLLER_TURNAROUNDS",
	.code  = 0xE3,
	.modmsk = AMD64_BASIC_ATTRS,
	.desc  = "Memory Controller Turnarounds",
	.ngrp = 1,
	.numasks = 4,
	.umasks  = {
		{ .uname = "CHIP_SELECT",
		  .udesc = "DIMM (chip select) turnaround",
		  .ucode = 0x01,
		},
		{ .uname = "READ_TO_WRITE",
		  .udesc = "Read to write turnaround",
		  .ucode = 0x02,
		},
		{ .uname = "WRITE_TO_READ",
		  .udesc = "Write to read turnaround",
		  .ucode = 0x04,
		},
		{ .uname = "ALL",
		  .udesc = "All Memory Controller Turnarounds",
		  .ucode = 0x07,
		  .uflags = AMD64_FL_DFL|AMD64_FL_NCOMBO,
		},
	 },
	},
/* 76 */{.name = "MEMORY_CONTROLLER_BYPASS",
	.code  = 0xE4,
	.modmsk = AMD64_BASIC_ATTRS,
	.desc  = "Memory Controller Bypass Counter Saturation",
	.ngrp = 1,
	.numasks = 5,
	.umasks  = {
		{ .uname = "HIGH_PRIORITY",
		  .udesc = "Memory controller high priority bypass",
		  .ucode = 0x01,
		},
		{ .uname = "LOW_PRIORITY",
		  .udesc = "Memory controller low priority bypass",
		  .ucode = 0x02,
		},
		{ .uname = "DRAM_INTERFACE",
		  .udesc = "DRAM controller interface bypass",
		  .ucode = 0x04,
		},
		{ .uname = "DRAM_QUEUE",
		  .udesc = "DRAM controller queue bypass",
		  .ucode = 0x08,
		},
		{ .uname = "ALL",
		  .udesc = "All sub-events selected",
		  .ucode = 0x0F,
		  .uflags = AMD64_FL_DFL|AMD64_FL_NCOMBO,
		},
	 },
	},
/* 77 */{.name = "SIZED_BLOCKS",
	.code  = 0xE5,
	.modmsk = AMD64_BASIC_ATTRS,
	.desc  = "Sized Blocks",
	.flags = AMD64_FL_K8_REV_D,
	.ngrp = 1,
	.numasks = 5,
	.umasks  = {
		{ .uname = "32_BYTE_WRITES",
		  .udesc = "32-byte Sized Writes",
		  .ucode = 0x04,
		},
		{ .uname = "64_BYTE_WRITES",
		  .udesc = "64-byte Sized Writes",
		  .ucode = 0x08,
		},
		{ .uname = "32_BYTE_READS",
		  .udesc = "32-byte Sized Reads",
		  .ucode = 0x10,
		},
		{ .uname = "64_BYTE_READS",
		  .udesc = "64-byte Sized Reads",
		  .ucode = 0x20,
		},
		{ .uname = "ALL",
		  .udesc = "All sub-events selected",
		  .ucode = 0x3C,
		  .uflags = AMD64_FL_DFL|AMD64_FL_NCOMBO,
		},
	 },
	},
/* 78 */{.name = "THERMAL_STATUS_AND_ECC_ERRORS",
	.code  = 0xE8,
	.modmsk = AMD64_BASIC_ATTRS,
	.desc  = "Thermal Status and ECC Errors",
	.flags = AMD64_FL_K8_REV_E,
	.ngrp = 1,
	.numasks = 7,
	.umasks  = {
		{ .uname = "CLKS_CPU_ACTIVE",
		  .udesc = "Number of clocks CPU is active when HTC is active",
		  .ucode = 0x01,
		  .uflags = AMD64_FL_K8_REV_F,
		},
		{ .uname = "CLKS_CPU_INACTIVE",
		  .udesc = "Number of clocks CPU clock is inactive when HTC is active",
		  .ucode = 0x02,
		  .uflags = AMD64_FL_K8_REV_F,
		},
		{ .uname = "CLKS_DIE_TEMP_TOO_HIGH",
		  .udesc = "Number of clocks when die temperature is higher than the software high temperature threshold",
		  .ucode = 0x04,
		  .uflags = AMD64_FL_K8_REV_F,
		},
		{ .uname = "CLKS_TEMP_THRESHOLD_EXCEEDED",
		  .udesc = "Number of clocks when high temperature threshold was exceeded",
		  .ucode = 0x08,
		  .uflags = AMD64_FL_K8_REV_F,
		},
		{ .uname = "DRAM_ECC_ERRORS",
		  .udesc = "Number of correctable and Uncorrectable DRAM ECC errors",
		  .ucode = 0x80,
		},
		{ .uname = "ALL",
		  .udesc = "All sub-events selected",
		  .ucode = 0x80,
		  .uflags = AMD64_FL_TILL_K8_REV_E|AMD64_FL_DFL|AMD64_FL_NCOMBO,
		},
		{ .uname = "ALL",
		  .udesc = "All sub-events selected",
		  .ucode = 0x8F,
		  .uflags = AMD64_FL_K8_REV_F|AMD64_FL_DFL|AMD64_FL_NCOMBO,
		},
	 },
	},
/* 79 */{.name = "CPU_IO_REQUESTS_TO_MEMORY_IO",
	.code  = 0xE9,
	.modmsk = AMD64_BASIC_ATTRS,
	.desc  = "CPU/IO Requests to Memory/IO",
	.flags = AMD64_FL_K8_REV_E,
	.ngrp = 1,
	.numasks = 9,
	.umasks  = {
		{ .uname = "I_O_TO_I_O",
		  .udesc = "I/O to I/O",
		  .ucode = 0x01,
		},
		{ .uname = "I_O_TO_MEM",
		  .udesc = "I/O to Mem",
		  .ucode = 0x02,
		},
		{ .uname = "CPU_TO_I_O",
		  .udesc = "CPU to I/O",
		  .ucode = 0x04,
		},
		{ .uname = "CPU_TO_MEM",
		  .udesc = "CPU to Mem",
		  .ucode = 0x08,
		},
		{ .uname = "TO_REMOTE_NODE",
		  .udesc = "To remote node",
		  .ucode = 0x10,
		},
		{ .uname = "TO_LOCAL_NODE",
		  .udesc = "To local node",
		  .ucode = 0x20,
		},
		{ .uname = "FROM_REMOTE_NODE",
		  .udesc = "From remote node",
		  .ucode = 0x40,
		},
		{ .uname = "FROM_LOCAL_NODE",
		  .udesc = "From local node",
		  .ucode = 0x80,
		},
		{ .uname = "ALL",
		  .udesc = "All sub-events selected",
		  .ucode = 0xFF,
		  .uflags = AMD64_FL_DFL|AMD64_FL_NCOMBO,
		},
	 },
	},
/* 80 */{.name = "CACHE_BLOCK",
	.code  = 0xEA,
	.modmsk = AMD64_BASIC_ATTRS,
	.desc  = "Cache Block Commands",
	.flags = AMD64_FL_K8_REV_E,
	.ngrp = 1,
	.numasks = 6,
	.umasks  = {
		{ .uname = "VICTIM_WRITEBACK",
		  .udesc = "Victim Block (Writeback)",
		  .ucode = 0x01,
		},
		{ .uname = "DCACHE_LOAD_MISS",
		  .udesc = "Read Block (Dcache load miss refill)",
		  .ucode = 0x04,
		},
		{ .uname = "SHARED_ICACHE_REFILL",
		  .udesc = "Read Block Shared (Icache refill)",
		  .ucode = 0x08,
		},
		{ .uname = "READ_BLOCK_MODIFIED",
		  .udesc = "Read Block Modified (Dcache store miss refill)",
		  .ucode = 0x10,
		},
		{ .uname = "READ_TO_DIRTY",
		  .udesc = "Change to Dirty (first store to clean block already in cache)",
		  .ucode = 0x20,
		},
		{ .uname = "ALL",
		  .udesc = "All sub-events selected",
		  .ucode = 0x3D,
		  .uflags = AMD64_FL_DFL|AMD64_FL_NCOMBO,
		},
	 },
	},
/* 81 */{.name = "SIZED_COMMANDS",
	.code  = 0xEB,
	.modmsk = AMD64_BASIC_ATTRS,
	.desc  = "Sized Commands",
	.ngrp = 1,
	.numasks = 8,
	.umasks  = {
		{ .uname = "NON_POSTED_WRITE_BYTE",
		  .udesc = "NonPosted SzWr Byte (1-32 bytes) Legacy or mapped I/O, typically 1-4 bytes",
		  .ucode = 0x01,
		},
		{ .uname = "NON_POSTED_WRITE_DWORD",
		  .udesc = "NonPosted SzWr Dword (1-16 dwords) Legacy or mapped I/O, typically 1 dword",
		  .ucode = 0x02,
		},
		{ .uname = "POSTED_WRITE_BYTE",
		  .udesc = "Posted SzWr Byte (1-32 bytes) Sub-cache-line DMA writes, size varies; also flushes of partially-filled Write Combining buffer",
		  .ucode = 0x04,
		},
		{ .uname = "POSTED_WRITE_DWORD",
		  .udesc = "Posted SzWr Dword (1-16 dwords) Block-oriented DMA writes, often cache-line sized; also processor Write Combining buffer flushes",
		  .ucode = 0x08,
		},
		{ .uname = "READ_BYTE_4_BYTES",
		  .udesc = "SzRd Byte (4 bytes) Legacy or mapped I/O",
		  .ucode = 0x10,
		},
		{ .uname = "READ_DWORD_1_16_DWORDS",
		  .udesc = "SzRd Dword (1-16 dwords) Block-oriented DMA reads, typically cache-line size",
		  .ucode = 0x20,
		},
		{ .uname = "READ_MODIFY_WRITE",
		  .udesc = "RdModWr",
		  .ucode = 0x40,
		},
		{ .uname = "ALL",
		  .udesc = "All sub-events selected",
		  .ucode = 0x7F,
		  .uflags = AMD64_FL_DFL|AMD64_FL_NCOMBO,
		},
	 },
	},
/* 82 */{.name = "PROBE",
	.code  = 0xEC,
	.modmsk = AMD64_BASIC_ATTRS,
	.desc  = "Probe Responses and Upstream Requests",
	.ngrp = 1,
	.numasks = 9,
	.umasks  = {
		{ .uname = "MISS",
		  .udesc = "Probe miss",
		  .ucode = 0x01,
		},
		{ .uname = "HIT_CLEAN",
		  .udesc = "Probe hit clean",
		  .ucode = 0x02,
		},
		{ .uname = "HIT_DIRTY_NO_MEMORY_CANCEL",
		  .udesc = "Probe hit dirty without memory cancel (probed by Sized Write or Change2Dirty)",
		  .ucode = 0x04,
		},
		{ .uname = "HIT_DIRTY_WITH_MEMORY_CANCEL",
		  .udesc = "Probe hit dirty with memory cancel (probed by DMA read or cache refill request)",
		  .ucode = 0x08,
		},
		{ .uname = "UPSTREAM_DISPLAY_REFRESH_READS",
		  .udesc = "Upstream display refresh reads",
		  .ucode = 0x10,
		},
		{ .uname = "UPSTREAM_NON_DISPLAY_REFRESH_READS",
		  .udesc = "Upstream non-display refresh reads",
		  .ucode = 0x20,
		},
		{ .uname = "ALL",
		  .udesc = "All sub-events selected",
		  .ucode = 0x3F,
		  .uflags = AMD64_FL_TILL_K8_REV_C|AMD64_FL_DFL|AMD64_FL_NCOMBO,
		},
		{ .uname = "UPSTREAM_WRITES",
		  .udesc = "Upstream writes",
		  .ucode = 0x40,
		  .uflags = AMD64_FL_K8_REV_D,
		},
		{ .uname = "ALL",
		  .udesc = "All sub-events selected",
		  .ucode = 0x7F,
		  .uflags = AMD64_FL_K8_REV_D|AMD64_FL_DFL|AMD64_FL_NCOMBO,
		},
	 },
	},
/* 83 */{.name = "GART",
	.code  = 0xEE,
	.modmsk = AMD64_BASIC_ATTRS,
	.desc  = "GART Events",
	.ngrp = 1,
	.numasks = 4,
	.umasks  = {
		{ .uname = "APERTURE_HIT_FROM_CPU",
		  .udesc = "GART aperture hit on access from CPU",
		  .ucode = 0x01,
		},
		{ .uname = "APERTURE_HIT_FROM_IO",
		  .udesc = "GART aperture hit on access from I/O",
		  .ucode = 0x02,
		},
		{ .uname = "MISS",
		  .udesc = "GART miss",
		  .ucode = 0x04,
		},
		{ .uname = "ALL",
		  .udesc = "All sub-events selected",
		  .ucode = 0x07,
		  .uflags = AMD64_FL_DFL|AMD64_FL_NCOMBO,
		},
	 },
	},
/* 84 */{.name = "HYPERTRANSPORT_LINK0",
	.code  = 0xF6,
	.modmsk = AMD64_BASIC_ATTRS,
	.desc  = "HyperTransport Link 0 Transmit Bandwidth",
	.ngrp = 1,
	.numasks = 5,
	.umasks  = {
		{ .uname = "COMMAND_DWORD_SENT",
		  .udesc = "Command dword sent",
		  .ucode = 0x01,
		},
		{ .uname = "DATA_DWORD_SENT",
		  .udesc = "Data dword sent",
		  .ucode = 0x02,
		},
		{ .uname = "BUFFER_RELEASE_DWORD_SENT",
		  .udesc = "Buffer release dword sent",
		  .ucode = 0x04,
		},
		{ .uname = "NOP_DWORD_SENT",
		  .udesc = "Nop dword sent (idle)",
		  .ucode = 0x08,
		},
		{ .uname = "ALL",
		  .udesc = "All sub-events selected",
		  .ucode = 0x0F,
		  .uflags = AMD64_FL_DFL|AMD64_FL_NCOMBO,
		},
	 },
	},
/* 85 */{.name = "HYPERTRANSPORT_LINK1",
	.code  = 0xF7,
	.modmsk = AMD64_BASIC_ATTRS,
	.desc  = "HyperTransport Link 1 Transmit Bandwidth",
	.ngrp = 1,
	.numasks = 5,
	.umasks  = {
		{ .uname = "COMMAND_DWORD_SENT",
		  .udesc = "Command dword sent",
		  .ucode = 0x01,
		},
		{ .uname = "DATA_DWORD_SENT",
		  .udesc = "Data dword sent",
		  .ucode = 0x02,
		},
		{ .uname = "BUFFER_RELEASE_DWORD_SENT",
		  .udesc = "Buffer release dword sent",
		  .ucode = 0x04,
		},
		{ .uname = "NOP_DWORD_SENT",
		  .udesc = "Nop dword sent (idle)",
		  .ucode = 0x08,
		},
		{ .uname = "ALL",
		  .udesc = "All sub-events selected",
		  .ucode = 0x0F,
		  .uflags = AMD64_FL_DFL|AMD64_FL_NCOMBO,
		},
	 },
	},
/* 86 */{.name = "HYPERTRANSPORT_LINK2",
	.code  = 0xF8,
	.modmsk = AMD64_BASIC_ATTRS,
	.desc  = "HyperTransport Link 2 Transmit Bandwidth",
	.ngrp = 1,
	.numasks = 5,
	.umasks  = {
		{ .uname = "COMMAND_DWORD_SENT",
		  .udesc = "Command dword sent",
		  .ucode = 0x01,
		},
		{ .uname = "DATA_DWORD_SENT",
		  .udesc = "Data dword sent",
		  .ucode = 0x02,
		},
		{ .uname = "BUFFER_RELEASE_DWORD_SENT",
		  .udesc = "Buffer release dword sent",
		  .ucode = 0x04,
		},
		{ .uname = "NOP_DWORD_SENT",
		  .udesc = "Nop dword sent (idle)",
		  .ucode = 0x08,
		},
		{ .uname = "ALL",
		  .udesc = "All sub-events selected",
		  .ucode = 0x0F,
		  .uflags = AMD64_FL_DFL|AMD64_FL_NCOMBO,
		},
	 },
	},
};

#define PME_AMD64_K8_EVENT_COUNT		(sizeof(amd64_k8_pe)/sizeof(amd64_entry_t))