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

#import "AbstractDetailsViewController.h"

@interface MovieDetailsViewController : AbstractDetailsViewController<TappableImageViewDelegate, NetflixAddMovieDelegate, UIActionSheetDelegate, NetflixModifyQueueDelegate, NetflixMoveMovieDelegate, MapViewControllerDelegate> {
@private
  Movie* movie;
  DVD* dvd;

  NetflixAccount* netflixAccount;
  Movie* netflixMovie;
  NetflixRatingsCell* netflixRatingsCell;
  NSArray* netflixStatusCells;

  NSMutableArray* filteredTheatersArray;
  NSMutableArray* allTheatersArray;
  NSMutableArray* showtimesArray;
  NSArray* trailersArray;
  NSArray* reviewsArray;
  NSDictionary* websites;

  ActionsView* actionsView;
  UIButton* bookmarkButton;

  BOOL filterTheatersByDistance;
  BOOL expandedDetails;

  UIImage* posterImage;
  TappableImageView* posterImageView;
  NSInteger posterCount;

  MPMoviePlayerController* moviePlayer;
}

- (id) initWithMovie:(Movie*) movie;

+ (UIImage*) posterForMovie:(Movie*) movie model:(Model*) model;

@end
