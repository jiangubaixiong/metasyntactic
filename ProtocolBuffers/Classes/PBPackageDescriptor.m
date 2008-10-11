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

#import "PBPackageDescriptor.h"

@interface PBPackageDescriptor()
    @property (copy) NSString* name;
    @property (copy) NSString* fullName;
    @property (retain) PBFileDescriptor* file;
@end


@implementation PBPackageDescriptor

@synthesize name;
@synthesize fullName;
@synthesize file;

- (void) dealloc {
    self.name = nil;
    self.fullName = nil;
    self.file = nil;

    [super dealloc];
}


- (id) initWithFullName:(NSString*) fullName_
                   name:(NSString*) name_
                   file:(PBFileDescriptor*) file_ {
    if (self = [super init]) {
        self.fullName = fullName_;
        self.name = name_;
        self.file = file_;
    }

    return self;
}

+ (PBPackageDescriptor*) descriptorWithFullName:(NSString*) fullName
                                           name:(NSString*) name
                                           file:(PBFileDescriptor*) file {
    return [[[PBPackageDescriptor alloc] initWithFullName:fullName
                                                     name:name
                                                     file:file] autorelease];
}

#if 0
public Message toProto()        { return file.toProto(); }
public String getName()         { return name;           }
public String getFullName()     { return fullName;       }
public FileDescriptor getFile() { return file;           }
#endif

@end