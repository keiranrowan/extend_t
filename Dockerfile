# --- Initial Setup ---
FROM gcc:4.9
WORKDIR /usr/src/extend_t
ARG doTest=FALSE
ARG doClean=TRUE
ENV ldir /usr/lib/
ENV hdir /usr/include/
COPY . .

# --- Install libarray ---

# Build Static Library
RUN echo "[extend_t] Building libarray...\n"
RUN gcc -c -o array.o ./array/array.c -std=c11
RUN ar rcs libarray.a array.o

# Install Library and Headers
RUN echo "[extend_t] Installing libarray...\n"
RUN cp -p libarray.a $ldir
RUN cp -p ./array/array.h $hdir

# Cleanup
RUN echo "[extend_t] Cleaning up...\n"
RUN if [ "$doClean" = "TRUE" ] ; then rm -rf array.o ; fi
RUN if [ "$doClean" = "TRUE" ] ; then rm -rf libarray.a ; fi

# Test (Optional)
RUN echo "[extend_t] Running test build...\n"
RUN if [ "$doTest" = "TRUE" ] ; then gcc ./array/test.c -larray -std=c11 -o test ; fi
RUN if [ "$doTest" = "TRUE" ] ; then ./test ; fi
