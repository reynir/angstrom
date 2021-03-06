/*----------------------------------------------------------------------------
    Copyright (c) 2017 Inhabited Type LLC.

    All rights reserved.

    Redistribution and use in source and binary forms, with or without
    modification, are permitted provided that the following conditions
    are met:

    1. Redistributions of source code must retain the above copyright
       notice, this list of conditions and the following disclaimer.

    2. Redistributions in binary form must reproduce the above copyright
       notice, this list of conditions and the following disclaimer in the
       documentation and/or other materials provided with the distribution.

    3. Neither the name of the author nor the names of his contributors
       may be used to endorse or promote products derived from this software
       without specific prior written permission.

    THIS SOFTWARE IS PROVIDED BY THE CONTRIBUTORS ``AS IS'' AND ANY EXPRESS
    OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
    WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
    DISCLAIMED.  IN NO EVENT SHALL THE AUTHORS OR CONTRIBUTORS BE LIABLE FOR
    ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
    DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
    OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
    HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,
    STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
    ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
    POSSIBILITY OF SUCH DAMAGE.
  ----------------------------------------------------------------------------*/

#include <string.h>
#include <caml/mlvalues.h>
#include <caml/bigarray.h>

void
angstrom_bigstring_blit_to_bytes(value vsrc, value vsrc_off, value vdst, value vdst_off, value vlen)
{
    void *src = ((void *)Caml_ba_data_val(vsrc)) + Int_val(vsrc_off),
         *dst = ((void *)String_val(vdst))       + Int_val(vdst_off);
    size_t len = Int_val(vlen);
    memcpy(dst, src, len);
}

void
angstrom_bigstring_blit_to_bigstring(value vsrc, value vsrc_off, value vdst, value vdst_off, value vlen)
{
    void *src = ((void *)Caml_ba_data_val(vsrc)) + Int_val(vsrc_off),
         *dst = ((void *)Caml_ba_data_val(vdst)) + Int_val(vdst_off);
    size_t len = Int_val(vlen);
    memcpy(dst, src, len);
}

void
angstrom_bigstring_blit_from_bytes(value vsrc, value vsrc_off, value vdst, value vdst_off, value vlen)
{
    void *src = ((void *)String_val(vsrc))       + Int_val(vsrc_off),
         *dst = ((void *)Caml_ba_data_val(vdst)) + Int_val(vdst_off);
    size_t len = Int_val(vlen);
    memcpy(dst, src, len);
}
