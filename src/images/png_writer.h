#ifndef RTC_DISPLAY_PNG_WRITER_H
#define RTC_DISPLAY_PNG_WRITER_H

#include "display/canvas.h"

#include <ostream>
#include <string>

class PNGWriter {
 public:
  explicit PNGWriter(Canvas *canvas);
  ~PNGWriter() = default;

  // Writes contents of canvas into *filename*.
  void WriteFile(std::string filename) const;
  // Writes into an arbitrary stream. Mostly used for testing.
  void WriteStream(std::ostream &stream) const;

 private:
  Canvas *canvas_;

  // Writes PNG signature 8 bits.
  static void WriteSignature(std::ostream &stream) ;
  // Writes Header that must follow the signature.
  void WriteHeader(std::ostream &stream) const;
  // Writes Image Data. May write multiple chunks.
  void WriteImageData(std::ostream &stream) const;
  // Writes footer that ends the PNG file.
  static void WriteFooter(std::ostream &stream) ;

  // Writes data for a chunk. Compression and must be done by caller. length must be less than 2^31.
  static void WriteChunk(std::ostream &stream, const int length, const std::string &type, const void *data) ;
};

#endif    // RTC_DISPLAY_PNG_WRITER_H
