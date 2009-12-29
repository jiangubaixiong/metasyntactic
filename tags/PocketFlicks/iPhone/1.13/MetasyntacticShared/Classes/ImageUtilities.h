// Copyright 2008 Cyrus Najmabadi
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

@interface ImageUtilities : NSObject {
}

+ (UIImage*) faultImage:(UIImage*) image;

+ (UIImage*) scaleImage:(UIImage*) image toSize:(CGSize) size;
+ (UIImage*) scaleImage:(UIImage*) image toHeight:(CGFloat) height;
+ (UIImage*) cropImage:(UIImage*) image toRect:(CGRect) rect;
+ (UIImage*) roundUpperLeftCornerOfImage:(UIImage*) image;
+ (UIImage*) roundLowerLeftCornerOfImage:(UIImage*) image;
+ (UIImage*) roundCornersOfImage:(UIImage*) image;
+ (UIImage*) makeGrayscale:(UIImage*) image;

+ (NSData*) scaleImageData:(NSData*) image toHeight:(CGFloat) height;

@end
