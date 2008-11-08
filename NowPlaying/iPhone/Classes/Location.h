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

#define UNKNOWN_DISTANCE FLT_MAX

@interface Location : NSObject<NSCopying> {
    double latitude;
    double longitude;
    NSString* address;
    NSString* city;
    NSString* state;
    NSString* postalCode;
    NSString* country;
}

@property double latitude;
@property double longitude;
@property (copy) NSString* address;
@property (copy) NSString* city;
@property (copy) NSString* state;
@property (copy) NSString* postalCode;
@property (copy) NSString* country;


+ (Location*) locationWithDictionary:(NSDictionary*) dictionary;
+ (Location*) locationWithLatitude:(double) latitude
                         longitude:(double) longitude;
+ (Location*) locationWithLatitude:(double) latitude
                         longitude:(double) longitude
                           address:(NSString*) address
                              city:(NSString*) city
                             state:(NSString*) state
                        postalCode:(NSString*) postalCode
                           country:(NSString*) country;

+ (BOOL) canReadDictionary:(NSDictionary*) dictionary;
- (NSDictionary*) dictionary;

- (NSString*) mapUrl;

- (double) distanceTo:(Location*) to;

- (NSString*) fullDisplayString;

@end