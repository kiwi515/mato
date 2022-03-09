#ifndef NW4R_UT_ROM_FONT_H
#define NW4R_UT_ROM_FONT_H
#include "ut_Font.h"

namespace nw4r
{
	namespace ut
	{
		struct RomFont : Font
		{
			static u16 mFontEncode;
			
			void * mBuffer;
			
			CharWidths mDefaultCharWidths;
			
			u16 mAlternateChar;
			
			RomFont();
			~RomFont();
			
			bool Load(void *);
			u32 GetRequireBufferSize();
			
			int GetWidth() const;
			int GetHeight() const;
			
			int GetAscent() const;
			int GetDescent() const;
			int GetBaselinePos() const;
			
			int GetCellHeight() const;
			int GetCellWidth() const;
			
			int GetMaxCharWidth() const;
			
			UNKWORD GetType() const;
			UNKWORD GetTextureFormat() const;
			
			int GetLineFeed() const;
			
			CharWidths GetDefaultCharWidths() const;
			void SetDefaultCharWidths(const CharWidths &);
			
			bool HandleUndefinedChar(u16) const; //inlined
			bool SetAlternateChar(u16);
			
			void SetLineFeed(int);
			int GetCharWidth(u16) const;
			CharWidths GetCharWidths(u16) const;
			
			void GetGlyph(Glyph *, u16) const;
			
			FontEncoding GetEncoding() const;
		};
	}
}

#endif