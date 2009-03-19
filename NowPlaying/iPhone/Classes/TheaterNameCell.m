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

#import "TheaterNameCell.h"

#import "Application.h"
#import "Model.h"
#import "Theater.h"

@interface TheaterNameCell()
@property (retain) Model* model;
@end


@implementation TheaterNameCell

@synthesize model;

- (void) dealloc {
    self.model = nil;

    [super dealloc];
}


- (id) initWithReuseIdentifier:(NSString*) reuseIdentifier
                         model:(Model*) model_ {
    if (self = [super initWithStyle:UITableViewCellStyleSubtitle
                    reuseIdentifier:reuseIdentifier]) {
        self.model = model_;
        self.textLabel.adjustsFontSizeToFitWidth = YES;
        self.textLabel.minimumFontSize = 12;
    }

    return self;
}


- (void) setTheater:(Theater*) theater {
    if ([model isFavoriteTheater:theater]) {
        self.textLabel.text = [NSString stringWithFormat:@"%@ %@", [Application starString], theater.name];
    } else {
        self.textLabel.text = theater.name;
    }

    self.detailTextLabel.text = [model simpleAddressForTheater:theater];
}

@end