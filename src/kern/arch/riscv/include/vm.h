#pragma once

#define PGROUNDUP(sz) (((sz) + PGSIZE-1) & ~(PGSIZE-1))
#define PGSIZE 4096

