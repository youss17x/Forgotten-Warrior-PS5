/*
 * PS5 port contributions and enhancements: Youss Riaal, 2026.
 * SPDX-License-Identifier: GPL-3.0-only
 * Applies to original port contributions only; see COPYRIGHT.md and NOTICE.md.
 * Preserve existing upstream notices. No relicensing of original game content.
 */
#pragma once
#include <cstdint>
#include <vector>

// Edge-aware 2x enlargement: preserve flat colors and round diagonal corners.
inline void enlarge_pixel_art(const uint32_t*src,int w,int h,int stride,std::vector<uint32_t>&dst){
 dst.resize(w*h*4);const int out_w=w*2;
 for(int y=0;y<h;y++)for(int x=0;x<w;x++){
  const uint32_t e=src[y*stride+x],b=src[(y?y-1:y)*stride+x],d=src[y*stride+(x?x-1:x)],f=src[y*stride+(x+1<w?x+1:x)],hh=src[(y+1<h?y+1:y)*stride+x];
  uint32_t a=e,c=e,g=e,i=e;
  if(b!=hh&&d!=f){a=d==b?d:e;c=b==f?f:e;g=d==hh?d:e;i=hh==f?f:e;}
  const int p=y*2*out_w+x*2;dst[p]=a;dst[p+1]=c;dst[p+out_w]=g;dst[p+out_w+1]=i;
 }
}
