//
//  IdenfyTakePhotoButton.swift
//  Sonect-iOS
//
//  Created by Marko Hlebar on 19/11/2019.
//  Copyright © 2019 Sonect. All rights reserved.
//

import UIKit

class IdenfyTakePhotoButton: UIButton {

    required init?(coder aDecoder: NSCoder) {
        super.init(coder: aDecoder)

        setTitle(NSLocalizedString("idenfy_take_photo",
                                   tableName: "Idenfy",
                                   bundle: Bundle.main,
                                   value: "",
                                   comment: ""),
                 for: .normal)
    }
}

