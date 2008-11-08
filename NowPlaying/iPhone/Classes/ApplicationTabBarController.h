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

@interface ApplicationTabBarController : UITabBarController<UITabBarControllerDelegate> {
    NowPlayingAppDelegate* appDelegate;
    MoviesNavigationController* moviesNavigationController;
    TheatersNavigationController* theatersNavigationController;
    UpcomingMoviesNavigationController* upcomingMoviesNavigationController;
    NumbersNavigationController* numbersNavigationController;
    DVDNavigationController* dvdNavigationController;
    SettingsNavigationController* settingsNavigationController;

    NSDate* lastRefreshDate;
}

@property (assign) NowPlayingAppDelegate* appDelegate;
@property (retain) MoviesNavigationController* moviesNavigationController;
@property (retain) TheatersNavigationController* theatersNavigationController;
@property (retain) UpcomingMoviesNavigationController* upcomingMoviesNavigationController;
@property (retain) NumbersNavigationController* numbersNavigationController;
@property (retain) DVDNavigationController* dvdNavigationController;
@property (retain) SettingsNavigationController* settingsNavigationController;
@property (retain) NSDate* lastRefreshDate;

+ (ApplicationTabBarController*) controllerWithAppDelegate:(NowPlayingAppDelegate*) appDelegate;

- (NowPlayingModel*) model;
- (NowPlayingController*) controller;

- (void) refresh;

- (void) popNavigationControllersToRoot;

- (void) switchToMovies;
- (void) switchToTheaters;
- (void) switchToUpcoming;
- (void) switchToDVD;

- (AbstractNavigationController*) selectedNavigationController;

@end