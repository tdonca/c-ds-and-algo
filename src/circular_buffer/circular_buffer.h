#ifndef CIRCULAR_BUFFER_H_
#define CIRCULAR_BUFFER_H_

#define BUFFER_SIZE 128

// Writes a given value to the front of the circular buffer, 
// overwriting the oldest value in a full buffer.
//
// Input: value - integer value to save in the buffer
void WriteHead(int value);

// Returns the oldest value in the buffer.
// Should not be called on an empty buffer.
//
// Output: the oldest int value in a non-empty buffer.
int ReadTail(void);

bool IsEmpty(void);

// Empties the buffer and its contents
void ClearBuffer(void);

#endif // CIRCULAR_BUFFER_H_